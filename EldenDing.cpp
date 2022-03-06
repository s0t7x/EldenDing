#include "EldenDing.h"

#define _BUFFER_SIZE		0x1000
#define _OFFSET_MapItemMan	0x3C51D10
#define _OFFSET_ItemDropRPC 0x548C90


uintptr_t getPIDByProcessName(std::string name) {
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	uintptr_t pid = 0;

	if (Process32First(snapshot, &entry) == TRUE)
	{
		while (Process32Next(snapshot, &entry) == TRUE)
		{
			if (_stricmp(entry.szExeFile, name.c_str()) == 0)
			{
				pid = entry.th32ProcessID;
			}
		}
	}

	CloseHandle(snapshot);
	return pid;
}

uintptr_t GetProcessBaseAddress(DWORD processID)
{
	DWORD_PTR   baseAddress = 0;
	HANDLE      processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
	HMODULE     *moduleArray;
	LPBYTE      moduleArrayBytes;
	DWORD       bytesRequired;

	if (processHandle)
	{
		if (EnumProcessModules(processHandle, NULL, 0, &bytesRequired))
		{
			if (bytesRequired)
			{
				moduleArrayBytes = (LPBYTE)LocalAlloc(LPTR, bytesRequired);

				if (moduleArrayBytes)
				{
					unsigned int moduleCount;

					moduleCount = bytesRequired / sizeof(HMODULE);
					moduleArray = (HMODULE *)moduleArrayBytes;

					if (EnumProcessModules(processHandle, moduleArray, bytesRequired, &bytesRequired))
					{
						baseAddress = (uintptr_t)moduleArray[0];
					}

					LocalFree(moduleArrayBytes);
				}
			}
		}

		CloseHandle(processHandle);
	}

	return baseAddress;
}

char itemDropShellcode[] = {
	0x48, 0x83, 0xEC, 0x48, 0x48, 0x8B, 0x0D,
	0x05, 0x1D, 0xC6, 0x03, // 7 MapItemMan
	0x45, 0x31, 0xC9, 0x45, 0x8D, 0x41, 0x01, 0x48, 0x8D, 0x15,
	0x0A, 0x00, 0x00, 0x00, // 21 ItemDropData
	0xE8,
	0x72, 0x8C, 0x55, 0x00, // 26 ItemDropRPC
	0x48, 0x83, 0xC4, 0x48, 0xC3
};

DWORD		dwEldenRingPid = 0;
HANDLE		hEldenRing = 0;
uintptr_t	pEldenRingBaseAddress = 0;

uintptr_t	pVirtualCodeSpace = 0;
uintptr_t	pVCSRIPBaseOffset = 0;
uintptr_t	pItemData = 0;

EldenDing::EldenDing(QWidget *parent)
    : QMainWindow(parent)
{
	// Get process information
	dwEldenRingPid = getPIDByProcessName("eldenring.exe");
	if (!dwEldenRingPid) exit(-1);

	hEldenRing = OpenProcess(PROCESS_ALL_ACCESS, NULL, dwEldenRingPid);
	if (!hEldenRing) exit(-2);

	pEldenRingBaseAddress = GetProcessBaseAddress(dwEldenRingPid);
	if (!pEldenRingBaseAddress) exit(-3);


	// Allocate virtual memory space inside process
	int allocationTry = 0;
	while (!pVirtualCodeSpace && allocationTry < 0xFF) {
		LPVOID pAddress = (LPVOID)(pEldenRingBaseAddress - (0x10000 * allocationTry));
		pVirtualCodeSpace = (uintptr_t)VirtualAllocEx(hEldenRing, pAddress, _BUFFER_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
		allocationTry++;
	}
	if (!pVirtualCodeSpace) exit(-4);

	pVCSRIPBaseOffset = pEldenRingBaseAddress - pVirtualCodeSpace;


	// Prepare shellcode
	uintptr_t ripMapItemMan = (uintptr_t)((0x3C51D10 + pVCSRIPBaseOffset) - 11);
	std::memcpy(itemDropShellcode + 7, &ripMapItemMan, 4);

	uintptr_t ripItemData = (uintptr_t)(sizeof(itemDropShellcode) - 25);
	std::memcpy(itemDropShellcode + 21, &ripItemData, 4);

	uintptr_t ripItemDropRPC = (uintptr_t)((0x548C90 + pVCSRIPBaseOffset) - 30);
	std::memcpy(itemDropShellcode + 26, &ripItemDropRPC, 4);


	// Write shellcode
	WriteProcessMemory(hEldenRing, (LPVOID)(pVirtualCodeSpace), itemDropShellcode, sizeof(itemDropShellcode), nullptr);


	// Prepare itemdata
	pItemData = pVirtualCodeSpace + sizeof(itemDropShellcode);


	// Setup UI
    ui.setupUi(this);

	itemTableModel = new ItemTableModel(this);

	proxyModel = new ProxyModel(this);
	proxyModel->setSourceModel(itemTableModel);

	ui.tvItems->setModel(proxyModel);
	ui.tvItems->setSortingEnabled(true);
	ui.tvItems->sortByColumn(2, Qt::AscendingOrder);
	ui.tvItems->verticalHeader()->setVisible(false);
	ui.tvItems->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tvItems->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tvItems->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tvItems->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui.tvItems->verticalHeader()->setDefaultSectionSize(24);

	QObject::connect(ui.leSearch, SIGNAL(textChanged(QString)),
		proxyModel, SLOT(setSearchName(QString)));

	QObject::connect(ui.cbType, SIGNAL(currentTextChanged(QString)),
		proxyModel, SLOT(setSearchType(QString)));

	QObject::connect(ui.tvItems->selectionModel(), SIGNAL(currentChanged(QModelIndex, QModelIndex)),
		this, SLOT(changeSelection(QModelIndex, QModelIndex)));

	QObject::connect(ui.pbSpawn, SIGNAL(clicked()),
		this, SLOT(spawnSelectedItem()));
}

EldenDing::~EldenDing() {
	if(pVirtualCodeSpace) VirtualFreeEx(hEldenRing, (LPVOID)pVirtualCodeSpace, _BUFFER_SIZE, MEM_RELEASE);
}

void EldenDing::changeSelection(QModelIndex current, QModelIndex previous) {
	QModelIndex _tIndex = proxyModel->mapToSource(current);
	QModelIndex hexIdIndex = itemTableModel->index(_tIndex.row(), 2, QModelIndex());
	ui.leItemIdDec->setText(QString::number(itemTableModel->data(hexIdIndex).toString().toInt(nullptr, 16), 10));
	ui.leItemIdHex->setText(itemTableModel->data(hexIdIndex).toString());
}

void EldenDing::spawnSelectedItem() {
	if (ui.leItemIdHex->text() == "") return;
	if (ui.sbQuantity->value() < 1) return;

	ItemDropData idd;
	idd.itemId = ui.leItemIdHex->text().toInt(nullptr, 16) & 0xFFFFFFFF;
	idd.quantity = ui.sbQuantity->value();

	bool bWriteRes = WriteProcessMemory(hEldenRing, (LPVOID)(pItemData), &idd, sizeof(ItemDropData), nullptr);
	if (bWriteRes) {
		HANDLE hThread = CreateRemoteThread(hEldenRing, 0, 0, (LPTHREAD_START_ROUTINE)(pVirtualCodeSpace), 0, 0, 0);
		WaitForSingleObject(hThread, INFINITE);
	}
}