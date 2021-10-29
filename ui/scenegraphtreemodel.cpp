#include "scenegraphtreemodel.h"

#include <QIcon>

#include <Qt3DCore/QComponent>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QNode>

SceneGraphTreeModel::SceneGraphTreeModel(Qt3DCore::QNode* rootNode, QObject* parent)
    : QAbstractItemModel(parent)
    , m_rootNode(rootNode)
    , m_entityIcon(":/images/circled-e.svg")
    , m_componentIcon(":/images/circled-c.svg")
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
    if (!index.isValid()) {
        return QVariant();
    }

    Qt3DCore::QNode* node = static_cast<Qt3DCore::QNode*>(index.internalPointer());

    switch (role) {
    case Qt::DisplayRole:
        return node->metaObject()->className();
    case Qt::DecorationRole:
        if (qobject_cast<Qt3DCore::QEntity*>(node) != nullptr) {
            return m_entityIcon;
        } else if (qobject_cast<Qt3DCore::QComponent*>(node) != nullptr) {
            return m_componentIcon;
        } else {
            return QVariant();
        }
    case Qt::UserRole + 1:
        QVariant::fromValue(node);
    default:
        return QVariant();
    }
}
