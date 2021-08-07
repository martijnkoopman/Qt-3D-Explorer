#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "renderwindow.h"
#include "scenegraphtreemodel.h"

#include <Qt3DExtras/Qt3DWindow>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup dock widgets
    splitDockWidget(ui->frameGraphDockWidget, ui->propertiesDockWidget, Qt::Orientation::Vertical);
    ui->frameGraphDockWidget->setTitleBarWidget(new QWidget);
    ui->sceneGraphDockWidget->setTitleBarWidget(new QWidget);
    tabifyDockWidget(ui->frameGraphDockWidget, ui->sceneGraphDockWidget);
    setTabPosition(Qt::AllDockWidgetAreas, QTabWidget::TabPosition::North);

    // Setup central widget
    RenderWindow* view = new RenderWindow();
    QWidget* renderWidget = QWidget::createWindowContainer(view);
    setCentralWidget(renderWidget);

    ui->sceneGraphTreeView->setModel(new SceneGraphTreeModel(view->rootEntity()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
