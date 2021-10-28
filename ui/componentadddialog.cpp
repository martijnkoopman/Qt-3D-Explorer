#include "componentadddialog.h"
#include "ui_componentadddialog.h"

ComponentAddDialog::ComponentAddDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ComponentAddDialog)
{
    ui->setupUi(this);

    // Unknown
    ui->componentComboBox->addItem("Qt3DRender::QSceneLoader");

    // Geometry renderer
    /*
     * Qt3DExtras::QConeMesh, Qt3DExtras::QCuboidMesh, Qt3DExtras::QCylinderMesh, Qt3DExtras::QExtrudedTextMesh,
     * Qt3DExtras::QPlaneMesh, Qt3DExtras::QSphereMesh, Qt3DExtras::QTorusMesh, and Qt3DRender::QMesh
     */
    ui->componentComboBox->addItem("Qt3DRender::QMesh");

    // Transform
    ui->componentComboBox->addItem("Qt3DRender::QTransform");

    // Materials
    ui->componentComboBox->addItem("Qt3DRender::QMaterial");
    /*
     * Qt3DExtras::QDiffuseMapMaterial, Qt3DExtras::QDiffuseSpecularMapMaterial, Qt3DExtras::QDiffuseSpecularMaterial,
     * Qt3DExtras::QGoochMaterial, Qt3DExtras::QMetalRoughMaterial, Qt3DExtras::QMorphPhongMaterial,
     * Qt3DExtras::QNormalDiffuseMapMaterial, Qt3DExtras::QNormalDiffuseSpecularMapMaterial,
     * Qt3DExtras::QPerVertexColorMaterial, Qt3DExtras::QPhongAlphaMaterial, Qt3DExtras::QPhongMaterial, and Qt3DExtras::QTextureMaterial
     */

    // Lights
    /*
     * Qt3DRender::QDirectionalLight, Qt3DRender::QPointLight, and Qt3DRender::QSpotLight
     */

    // CameraLens
}

ComponentAddDialog::~ComponentAddDialog()
{
    delete ui;
}
