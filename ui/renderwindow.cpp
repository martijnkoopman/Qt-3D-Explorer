#include "renderwindow.h"

#include "application.h"

RenderWindow::RenderWindow(QScreen* screen, Qt3DRender::API api)
    : Qt3DExtras::Qt3DWindow(screen, api)
{
    Application* app = Application::instance();
    setRootEntity(&app->rootEntity());
}

void RenderWindow::setRootEntity(Qt3DCore::QEntity* root)
{
    m_rootEntity = root;
    Qt3DExtras::Qt3DWindow::setRootEntity(root);
}

Qt3DCore::QEntity* RenderWindow::rootEntity() const
{
    return m_rootEntity;
}
