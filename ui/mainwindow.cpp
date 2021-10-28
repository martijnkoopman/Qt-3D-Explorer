#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "framegraphtreemodel.h"
#include "scenegraphtreemodel.h"

#include <QFileDialog>

#include <Qt3DCore/QEntity>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DRender/QSceneLoader>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_renderWindow(new RenderWindow())
{
    ui->setupUi(this);

    // Setup dock widgets
    splitDockWidget(ui->frameGraphDockWidget, ui->propertiesDockWidget, Qt::Orientation::Vertical);
    ui->frameGraphDockWidget->setTitleBarWidget(new QWidget);
    ui->sceneGraphDockWidget->setTitleBarWidget(new QWidget);
    tabifyDockWidget(ui->frameGraphDockWidget, ui->sceneGraphDockWidget);
    setTabPosition(Qt::AllDockWidgetAreas, QTabWidget::TabPosition::North);

    // Setup central widget
    QWidget* renderWidget = QWidget::createWindowContainer(m_renderWindow);
    setCentralWidget(renderWidget);

    // Setup scene graph tree view
    auto sceneGraphModel = new SceneGraphTreeModel(m_renderWindow->rootEntity());
    ui->sceneGraphTreeView->setModel(sceneGraphModel);

    connect(ui->sceneGraphTreeView, &QAbstractItemView::clicked, this, [=](const QModelIndex& index) {
        QVariant variant = sceneGraphModel->data(index, Qt::UserRole + 1);
        Qt3DCore::QNode* node = qvariant_cast<Qt3DCore::QNode*>(variant);
        ui->propertiesForm->setNode(node);
    });

    // Setup frame graph tree view
    auto frameGraphModel = new FrameGraphTreeModel(m_renderWindow->activeFrameGraph());
    ui->frameGraphTreeView->setModel(frameGraphModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showOpenFileDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
        tr("All Supported Files (*.3ds *.3mf *.ac3d *.blend *.bvh *.dae *.dxf *.fbx *.gltf *.obj *.off *.ply *.stl);;3DS Files (*.3ds);;3MF Files (*.3mf);;AC3D  Files (*.ac3d);;Blender Files (*.blend);;BVH Files (*.bvh);;DAE Files (*.dae);;DXF Files (*.dxf);;FBX Files (*.fbx);;GLTF Files (*.gltf);;OBJ Files (*.obj);;OFF Files (*.off);;PLY Files (*.ply);;STL Files (*.stl)"));

    Qt3DCore::QEntity* entity = new Qt3DCore::QEntity(m_renderWindow->rootEntity());
    auto component = new Qt3DRender::QSceneLoader(entity);
    component->setSource(QUrl::fromLocalFile(fileName));
}
