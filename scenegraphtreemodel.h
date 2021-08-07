#ifndef SCENEGRAPHTREEMODEL_H
#define SCENEGRAPHTREEMODEL_H

#include <QAbstractItemModel>

#include <Qt3DCore/QEntity>

class SceneGraphTreeModel : public QAbstractItemModel {
    Q_OBJECT
public:
    explicit SceneGraphTreeModel(Qt3DCore::QNode* rootNode, QObject* parent = nullptr);

    Q_INVOKABLE virtual QModelIndex index(int row, int column,
        const QModelIndex& parent = QModelIndex()) const override;
    Q_INVOKABLE virtual QModelIndex parent(const QModelIndex& child) const override;
    Q_INVOKABLE virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    Q_INVOKABLE virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    Q_INVOKABLE virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

private:
    Qt3DCore::QNode* m_rootNode;
};

#endif // SCENEGRAPHTREEMODEL_H
