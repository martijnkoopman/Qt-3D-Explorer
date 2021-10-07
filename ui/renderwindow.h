#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <Qt3DExtras/Qt3DWindow>

class RenderWindow : public Qt3DExtras::Qt3DWindow {
    Q_OBJECT
public:
    RenderWindow(QScreen* screen = nullptr, Qt3DRender::API api = Qt3DRender::API::OpenGL);

    void setRootEntity(Qt3DCore::QEntity* root);
    Qt3DCore::QEntity* rootEntity() const;

private:
    using Qt3DExtras::Qt3DWindow::setActiveFrameGraph;
    using Qt3DExtras::Qt3DWindow::setRootEntity;

    Qt3DCore::QEntity* m_rootEntity;
};

#endif // RENDERWINDOW_H
