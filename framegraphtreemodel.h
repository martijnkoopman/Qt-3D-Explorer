#ifndef FRAMEGRAPHTREEMODEL_H
#define FRAMEGRAPHTREEMODEL_H

#include <QAbstractItemModel>

#include <Qt3DRender/QFrameGraphNode>

#include <functional>

class FrameGraphTreeModel : public QAbstractItemModel {
    Q_OBJECT
public:
    explicit FrameGraphTreeModel(Qt3DRender::QFrameGraphNode* rootNode, QObject* parent = nullptr);

    Q_INVOKABLE virtual QModelIndex index(int row, int column,
        const QModelIndex& parent = QModelIndex()) const override;
    Q_INVOKABLE virtual QModelIndex parent(const QModelIndex& child) const override;
    Q_INVOKABLE virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    Q_INVOKABLE virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    Q_INVOKABLE virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

protected:
    std::function<QList<Qt3DRender::QFrameGraphNode*>(const QList<Qt3DCore::QNode*>& nodes)> m_frameGraphNodes;

private:
    Qt3DRender::QFrameGraphNode* m_rootNode;
};

#endif // FRAMEGRAPHTREEMODEL_H
