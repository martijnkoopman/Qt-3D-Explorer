#include "application.h"
#include "ui/mainwindow.h"

int main(int argc, char *argv[])
{
    Application app(argc, argv);

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

    MainWindow window;
    window.show();
    return app.exec();
}
