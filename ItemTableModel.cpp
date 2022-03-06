#include <fstream>
#include <qdebug.h>

#include "ItemTableModel.h"
#include "json.hpp"

ItemTableModel::ItemTableModel(QObject *parent)
	: QAbstractTableModel(parent)
{
	//this->m_itemList.append(itemModel("goods", "Golden Rune [1]", 0x40000B54));
	//this->m_itemList.append(itemModel("goods", "test", 0x40000B56));

	std::ifstream iFStream("./data.json");

	if (iFStream.is_open()) {
		try {
			nlohmann::json j = nlohmann::json::parse(iFStream, nullptr, true);
			for (auto& e : j.items()) {
				QString currentType = QString(e.key().c_str());
				int currentTypeOffset = e.value()["offset"];

				for (auto& i : e.value()["items"]) {
					this->m_itemList.append(itemModel(currentType, QString(i["name"].get<std::string>().c_str()), currentTypeOffset + i["id"].get<int>()));
				}
			}
		}
		catch (nlohmann::detail::type_error err)
		{
			// output exception information
			qDebug() << err.what();
		}
	}
	iFStream.close();
}

int ItemTableModel::columnCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return 3;
}

int ItemTableModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return m_itemList.size();
}

QVariant ItemTableModel::data(const QModelIndex & index,
	int role) const {
	if (!index.isValid())
		return QVariant();
	if (index.row() >= m_itemList.size() || index.row() < 0)
		return QVariant();

	if (role == Qt::DisplayRole) {
		const itemModel& item = m_itemList.at(index.row());
		switch (index.column()) {
		case 0:
			return item.itemName;
		case 1:
			return item.typeName;
		case 2:
			return item.hexId;
		default:
			return QVariant();
		}
	}
	else if (role == Qt::TextAlignmentRole) {
		if (index.column() == 0)
			return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
		else
			return Qt::AlignCenter;
	}
	return QVariant();
}

QVariant ItemTableModel::headerData(int section,
	Qt::Orientation orientation,
	int role) const {
	if (role != Qt::DisplayRole)
		return QVariant();

	if (orientation == Qt::Horizontal) {
		switch (section) {
		case 0:
			return tr("Name");
		case 1:
			return tr("Type");
		case 2:
			return tr("Id (hex)");
		default:
			return QVariant();
		}
	}
	return section + 1;
}

ItemTableModel::~ItemTableModel()
{
}
