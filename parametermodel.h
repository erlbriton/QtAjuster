#ifndef PARAMETERMODEL_H
#define PARAMETERMODEL_H

#include <QAbstractTableModel>
#include <vector>

struct Parameter {
    int id;
    QString name;
    double value;
    QString unit;
};

class ParameterModel : public QAbstractTableModel {
    Q_OBJECT
public:
    enum ParameterRoles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        ValueRole,
        UnitRole
    };

    explicit ParameterModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Это критически важно для связи с QML
    QHash<int, QByteArray> roleNames() const override;

    void addItem(const Parameter &item);

private:
    std::vector<Parameter> items;
};

#endif // PARAMETERMODEL_H
