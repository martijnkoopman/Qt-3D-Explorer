#include "framegraphtreemodel.h"

#include <algorithm>

FrameGraphTreeModel::FrameGraphTreeModel(Qt3DRender::QFrameGraphNode* rootNode, QObject* parent)
    : QAbstractItemModel(parent)
    , m_rootNode(rootNode)
    , m_frameGraphNodes([](const QList<Qt3DCore::QNode*>& nodes) {
        QList<Qt3DCore::QNode*> outputNodes;
        std::copy_if(nodes.begin(), nodes.end(), std::back_inserter(outputNodes),
            [](Qt3DCore::QNode* n) { return qobject_cast<Qt3DRender::QFrameGraphNode*>(n) != nullptr; });

        QList<Qt3DRender::QFrameGraphNode*> frameGraphNodes;
        std::transform(outputNodes.begin(), outputNodes.end(), std::back_inserter(frameGraphNodes), [](Qt3DCore::QNode* n) {
            return qobject_cast<Qt3DRender::QFrameGraphNode*>(n);
        });
        return frameGraphNodes;
    })
{
}

QModelIndex FrameGraphTreeModel::index(int row, int column, const QModelIndex& parent) const
{
    Q_UNUSED(column);
    Qt3DRender::QFrameGraphNode* parentNode = (!parent.isValid() ? m_rootNode : static_cast<Qt3DRender::QFrameGraphNode*>(parent.internalPointer()));
    Qt3DRender::QFrameGraphNode* childNode = m_frameGraphNodes(parentNode->childNodes())[row]; // TODO: Bounds checking
    QModelIndex result = createIndex(row, 0, childNode);
    return result;
}

QModelIndex FrameGraphTreeModel::parent(const QModelIndex& child) const
{
    if (!child.isValid()) {
        return QModelIndex();
    }

    Qt3DRender::QFrameGraphNode* childNode = static_cast<Qt3DRender::QFrameGraphNode*>(child.internalPointer());
    Qt3DRender::QFrameGraphNode* parentNode = childNode->parentFrameGraphNode();

    if (parentNode == m_rootNode)
        return QModelIndex();

    int parentRow = m_frameGraphNodes(parentNode->parentNode()->childNodes()).indexOf(parentNode);

    QModelIndex result = createIndex(parentRow, 0, parentNode);
    return result;
}

int FrameGraphTreeModel::rowCount(const QModelIndex& parent) const
{
    if (parent.column() > 0) {
        return 0;
    }

    Qt3DRender::QFrameGraphNode* parentNode = (!parent.isValid() ? m_rootNode : static_cast<Qt3DRender::QFrameGraphNode*>(parent.internalPointer()));
    int result = parentNode->childNodes().count();
    return result;
}

int FrameGraphTreeModel::columnCount(const QModelIndex& parent) const
{
    return 1;
}

QVariant FrameGraphTreeModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    Qt3DRender::QFrameGraphNode* node = static_cast<Qt3DRender::QFrameGraphNode*>(index.internalPointer());

    return node->metaObject()->className();
}
