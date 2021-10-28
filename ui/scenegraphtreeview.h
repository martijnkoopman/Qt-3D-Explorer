#ifndef SCENEGRAPHTREEVIEW_H
#define SCENEGRAPHTREEVIEW_H

#include <QTreeView>

class SceneGraphTreeView : public QTreeView {
    Q_OBJECT
public:
    SceneGraphTreeView(QWidget* parent = nullptr);

    void setModel(QAbstractItemModel* model) override;

protected slots:
    void showCustomContextMenu(const QPoint& pos);
};

#endif // SCENEGRAPHTREEVIEW_H
