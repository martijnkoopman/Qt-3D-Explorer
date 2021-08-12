#include "scenegraphtreemodel.h"

SceneGraphTreeModel::SceneGraphTreeModel(Qt3DCore::QNode* rootNode, QObject* parent)
    : QAbstractItemModel(parent)
    , m_rootNode(rootNode)
{
}

QModelIndex SceneGraphTreeModel::index(int row, int column, const QModelIndex& parent) const
{
    Q_UNUSED(column);
    Qt3DCore::QNode* parentNode = (!parent.isValid() ? m_rootNode : static_cast<Qt3DCore::QNode*>(parent.internalPointer()));
    Qt3DCore::QNode* childNode = parentNode->childNodes()[row]; // TODO: Bounds checking
    QModelIndex result = createIndex(row, 0, childNode);
    return result;
}

QModelIndex SceneGraphTreeModel::parent(const QModelIndex& child) const
{
    if (!child.isValid()) {
        return QModelIndex();
    }

    Qt3DCore::QNode* childNode = static_cast<Qt3DCore::QNode*>(child.internalPointer());
    Qt3DCore::QNode* parentNode = childNode->parentNode();

    if (parentNode == m_rootNode)
        return QModelIndex();

    int parentRow = parentNode->parentNode()->childNodes().indexOf(parentNode);

    QModelIndex result = createIndex(parentRow, 0, parentNode);
    return result;
}

int SceneGraphTreeModel::rowCount(const QModelIndex& parent) const
{
    if (parent.column() > 0) {
        return 0;
    }

    Qt3DCore::QNode* parentNode = (!parent.isValid() ? m_rootNode : static_cast<Qt3DCore::QNode*>(parent.internalPointer()));
    int result = parentNode->childNodes().count();
    return result;
}

int SceneGraphTreeModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return 1;
}

QVariant SceneGraphTreeModel::data(const QModelIndex& index, int role) const
{
    QVariant returnValue;

    if (!index.isValid()) {
        return returnValue;
    }

    Qt3DCore::QNode* node = static_cast<Qt3DCore::QNode*>(index.internalPointer());

    switch (role) {
    case Qt::DisplayRole:
        return node->metaObject()->className();
    case Qt::UserRole + 1:
        returnValue.setValue(node);
        return returnValue;
    default:
        return returnValue;
    }
}
