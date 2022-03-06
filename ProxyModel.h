#pragma once

#include <QSortFilterProxyModel>

class ProxyModel : public QSortFilterProxyModel
{
	Q_OBJECT
public:
	ProxyModel(QObject* parent = 0);
	bool filterAcceptsRow(int source_row,
		const QModelIndex &source_parent) const;
	QVariant headerData(int section, Qt::Orientation orientation,
		int role) const;

public slots:
	void setSearchName(QString input);
	void setSearchType(QString input);

private:
	QString searchName;
	QString searchType;
};
