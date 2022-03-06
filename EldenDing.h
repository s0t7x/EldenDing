#pragma once
#include <Windows.h>
#include <tlhelp32.h>
#include <Psapi.h>

#include <QtWidgets/QMainWindow>
#include "ui_EldenDing.h"

#include "ItemTableModel.h"
#include "ProxyModel.h"

struct ItemDropData {
	int itemId = 0x40000B54;
	int quantity = 1;
	int _jnk0x8 = 0;
	int _jnk0xC = -1;
};

class EldenDing : public QMainWindow
{
    Q_OBJECT

public:
    EldenDing(QWidget *parent = Q_NULLPTR);
	~EldenDing();

private:
    Ui::EldenDingClass ui;
	ItemTableModel * itemTableModel;
	ProxyModel * proxyModel;

public slots:
	void changeSelection(QModelIndex current, QModelIndex previous);
	void spawnSelectedItem();
};
