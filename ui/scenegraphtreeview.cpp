#include "scenegraphtreeview.h"

#include "scenegraphtreemodel.h"

#include <QMenu>

SceneGraphTreeView::SceneGraphTreeView(QWidget* parent)
    : QTreeView(parent)
{
    setRootIndex(QModelIndex());

    // Set up context menu
    this->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    connect(this, &QWidget::customContextMenuRequested, this, &SceneGraphTreeView::showCustomContextMenu);
}

void SceneGraphTreeView::setModel(QAbstractItemModel* model)
{
    //    auto sceneGraphTreeModel = qobject_cast<SceneGraphTreeModel*>(model);
    //    if (sceneGraphTreeModel != nullptr) {
    //        setRootIndex(sceneGraphTreeModel->rootIndex());
    //    }

    QTreeView::setModel(model);
}

void SceneGraphTreeView::showCustomContextMenu(const QPoint& pos)
{
    auto sceneGraphTreeModel = qobject_cast<SceneGraphTreeModel*>(model());
    if (sceneGraphTreeModel == nullptr) {
        qWarning() << "SceneGraphTreeView's model is not an instance of SceneGraphTreeModel";
        return;
    }

    QModelIndex index = this->indexAt(pos);
    if (!index.isValid()) {
        return;
    }

    auto menu = new QMenu();
    menu->addAction("Add component");
    menu->addSeparator();
    menu->addAction("Add child");
    menu->addAction("Delete");
    menu->exec(this->viewport()->mapToGlobal(pos));
}
