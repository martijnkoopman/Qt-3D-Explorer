#include "mainwindow.h"
#include "renderwindow.h"

#include <QApplication>
#include <QScreen>

#include <Qt3DCore/QAspectEngine>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QSkyboxEntity>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DInput/QInputAspect>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QPointLight>
#include <Qt3DRender/QRenderAspect>
#include <Qt3DRender/QRenderSettings>
#include <Qt3DRender/QSceneLoader>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //    auto renderWindow = new RenderWindow();
    //    renderWindow->defaultFrameGraph()->setClearColor(QColor(QRgb(0xFFFFFF)));

    //    QWidget* renderWidget = QWidget::createWindowContainer(renderWindow);
    //    QSize screenSize = renderWindow->screen()->size();
    //    renderWidget->setMinimumSize(QSize(200, 100));
    //    renderWidget->setMaximumSize(screenSize);

    //    Qt3DCore::QAspectEngine engine;
    //    engine.registerAspect(new Qt3DRender::QRenderAspect());
    //    Qt3DInput::QInputAspect* input = new Qt3DInput::QInputAspect;
    //    engine.registerAspect(input);
    //    engine.setRootEntity(createScene());

    //    Qt3DRender::QPickingSettings* pickingSettings = renderWindow->renderSettings()->pickingSettings();
    //    // pickingSettings->setFaceOrientationPickingMode(
    //    //    Qt3DRender::QPickingSettings::FrontFace);
    //    pickingSettings->setPickMethod(Qt3DRender::QPickingSettings::TrianglePicking);
    //    pickingSettings->setPickResultMode(Qt3DRender::QPickingSettings::NearestPick);

    MainWindow w;
    w.show();
    return a.exec();
}
