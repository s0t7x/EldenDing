#include "ProxyModel.h"

ProxyModel::ProxyModel(QObject *parent) : QSortFilterProxyModel(parent),
searchName("")
{
}

void ProxyModel::setSearchName(QString name) {
	if (searchName != name)
		searchName = name;
	invalidateFilter();
}

void ProxyModel::setSearchType(QString name) {
	if (searchType != name)
		searchType = name;
	invalidateFilter();
}

bool ProxyModel::filterAcceptsRow(int source_row,
	const QModelIndex &source_parent) const {

	QModelIndex iItemName = sourceModel()->index(source_row, 0, source_parent);
	QModelIndex iItemType = sourceModel()->index(source_row, 1, source_parent);

	if (searchType.length() < 1) {
		if (searchName.length() < 1) return true;
		if (sourceModel()->data(iItemName).toString().toLower().contains(searchName.toLower()))
			return true;
		return false;
	}

	if (sourceModel()->data(iItemType).toString().toLower().contains(searchType.toLower())) {
		if (searchName.length() < 1) return true;
		if (sourceModel()->data(iItemName).toString().toLower().contains(searchName.toLower()))
			return true;
		return false;
	}

	return false;
}

QVariant ProxyModel::headerData(int section, Qt::Orientation orientation,
	int role) const {
	return sourceModel()->headerData(section, orientation,
		role);
}