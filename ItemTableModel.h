#pragma once

#include <QAbstractTableModel>

struct itemModel {
	itemModel(const QString& _typeName = QString(), const QString& _itemName = QString(), const int id = 0)
		: typeName(_typeName), itemName(_itemName), hexId(QString::number(id, 16))
	{}

	QString typeName;
	QString itemName;
	QString hexId;
};

class ItemTableModel : public QAbstractTableModel
{
	Q_OBJECT

private:
	QList<itemModel> m_itemList;

public:
	ItemTableModel(QObject *parent);
	~ItemTableModel();

	int rowCount(const QModelIndex &parent = QModelIndex()) const;

	int columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};
