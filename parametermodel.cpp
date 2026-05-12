#include "parametermodel.h"

ParameterModel::ParameterModel(QObject *parent) : QAbstractTableModel(parent) {
    // Добавим пару тестовых строк, чтобы при запуске в браузере таблица не была пустой
    addItem({1, "Температура", 22.5, "°C"});
    addItem({2, "Давление", 101.3, "кПа"});
}

int ParameterModel::rowCount(const QModelIndex &) const {
    return static_cast<int>(items.size());
}

int ParameterModel::columnCount(const QModelIndex &) const {
    return 3; // У нас три колонки: Имя, Значение, Ед. изм.
}

QVariant ParameterModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= static_cast<int>(items.size()))
        return QVariant();

    const auto &item = items[static_cast<size_t>(index.row())];

    // QML будет запрашивать данные, используя эти роли
    switch (role) {
    case NameRole:  return item.name;
    case ValueRole: return item.value;
    case UnitRole:  return item.unit;
    default:        return QVariant();
    }
}

QHash<int, QByteArray> ParameterModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "p_name";   // Теперь в QML доступно свойство p_name
    roles[ValueRole] = "p_value"; // Теперь в QML доступно свойство p_value
    roles[UnitRole] = "p_unit";   // Теперь в QML доступно свойство p_unit
    return roles;
}

void ParameterModel::addItem(const Parameter &item) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    items.push_back(item);
    endInsertRows();
}
