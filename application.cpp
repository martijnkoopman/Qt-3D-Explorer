#include "application.h"

#include "components/propertycomponent.h"

#include <Qt3DRender/QSceneLoader>

Application::Application(int& argc, char** argv)
    : QApplication(argc, argv)
    , m_rootEntity()
{
    setupScene();
}

Application* Application::instance()
{
    return static_cast<Application*>(QCoreApplication::instance());
}

Qt3DCore::QEntity& Application::rootEntity()
{
    return m_rootEntity;
}

void Application::setupScene()
{
    auto childEntity = new Qt3DCore::QEntity(&rootEntity());
    auto propertyComponent = new PropertyComponent(childEntity);

    //auto sceneLoader = new Qt3DRender::QSceneLoader(scene);

    //    Qt3DRender::QMaterial* material = new Qt3DExtras::QPhongMaterial(scene);
    //    Qt3DCore::QEntity* torusEntity = new Qt3DCore::QEntity(scene);
    //    Qt3DExtras::QTorusMesh* torusMesh = new Qt3DExtras::QTorusMesh;
    //    torusMesh->setRadius(5);
    //    torusMesh->setMinorRadius(1);
    //    torusMesh->setRings(100);
    //    torusMesh->setSlices(20);

    //    Qt3DCore::QTransform* torusTransform = new Qt3DCore::QTransform;
    //    torusTransform->setScale3D(QVector3D(1.5, 1, 0.5));
    //    torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 45.0f));

    //    torusEntity->addComponent(torusMesh);
    //    torusEntity->addComponent(torusTransform);
    //    torusEntity->addComponent(material);

    //    Qt3DCore::QEntity* sphereEntity = new Qt3DCore::QEntity(scene);
    //    Qt3DExtras::QSphereMesh* sphereMesh = new Qt3DExtras::QSphereMesh;
    //    sphereMesh->setRadius(3);
    //    sphereMesh->setGenerateTangents(true);

    //    Qt3DCore::QTransform* sphereTransform = new Qt3DCore::QTransform;
    //    Qt3DExtras::QOrbitCameraController* controller = new Qt3DExtras::QOrbitCameraController(sphereTransform);
    //    //controller->setTarget(sphereTransform);
    //    //controller->setRadius(20.0f);

    //    QPropertyAnimation* sphereRotateTransformAnimation = new QPropertyAnimation(sphereTransform);
    //    sphereRotateTransformAnimation->setTargetObject(controller);
    //    sphereRotateTransformAnimation->setPropertyName("angle");
    //    sphereRotateTransformAnimation->setStartValue(QVariant::fromValue(0));
    //    sphereRotateTransformAnimation->setEndValue(QVariant::fromValue(360));
    //    sphereRotateTransformAnimation->setDuration(10000);
    //    sphereRotateTransformAnimation->setLoopCount(-1);
    //    sphereRotateTransformAnimation->start();

    //    sphereEntity->addComponent(sphereMesh);
    //    sphereEntity->addComponent(sphereTransform);
    //    sphereEntity->addComponent(material);

    //    // Camera
    //    Qt3DRender::QCamera* cam = camera();
    //    cam->lens()->setPerspectiveProjection(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
    //    cam->setPosition(QVector3D(0, 0, 40.0f));
    //    cam->setViewCenter(QVector3D(0, 0, 0));

    //    // For camera controls
    //    Qt3DExtras::QOrbitCameraController* camController = new Qt3DExtras::QOrbitCameraController(scene);
    //    camController->setLinearSpeed(50.0f);
    //    camController->setLookSpeed(180.0f);
    //    camController->setCamera(cam);
}
