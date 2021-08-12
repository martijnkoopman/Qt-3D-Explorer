#include "propertiesform.h"
#include "ui_propertiesform.h"

#include <QLabel>
#include <QMetaProperty>

PropertiesForm::PropertiesForm(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::PropertiesForm)
    , m_node(nullptr)
{
    ui->setupUi(this);
}

PropertiesForm::~PropertiesForm()
{
    delete ui;
}

Qt3DCore::QNode* PropertiesForm::node() const
{
    return m_node;
}

void PropertiesForm::setNode(Qt3DCore::QNode* n)
{
    if (m_node == n) {
        return;
    }

    m_node = n;

    setupUI();

    emit nodeChanged(m_node);
}

void PropertiesForm::setupUI()
{
    // Clear UI
    QLayoutItem* item;
    while ((item = ui->scrollAreaWidgetContents->layout()->takeAt(0)) != nullptr) {
        if (item->widget() != nullptr) {
            delete item->widget();
        }
        delete item;
    }

    if (m_node == nullptr) {
        return;
    }

    const QMetaObject* metaObj = m_node->metaObject();
    while (metaObj != nullptr) {

        QLabel* label = new QLabel(ui->scrollAreaWidgetContents);
        label->setText("--- " + QString::fromLocal8Bit(metaObj->className()) + "---");
        ui->scrollAreaWidgetContents->layout()->addWidget(label);

        for (int i = metaObj->propertyCount() - 1; i >= metaObj->propertyOffset(); i--) {
            int a = metaObj->propertyOffset();
            QMetaProperty property = metaObj->property(i);

            QLabel* label = new QLabel(ui->scrollAreaWidgetContents);
            label->setText(QString::fromLocal8Bit(property.name()) + " " + QString::fromLocal8Bit(property.typeName()));
            ui->scrollAreaWidgetContents->layout()->addWidget(label);
        }

        metaObj = metaObj->superClass();
    }
}
