#include "propertiesform.h"
#include "ui_propertiesform.h"

#include "floatpropertyedit.h"

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMetaProperty>

PropertiesForm::PropertiesForm(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::PropertiesForm)
    , m_node(nullptr)
    , m_propertyEdits()
{
    ui->setupUi(this);

    connect(ui->applyButton, &QPushButton::clicked, this, &PropertiesForm::apply);
    connect(ui->revertButton, &QPushButton::clicked, this, &PropertiesForm::revert);
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

void PropertiesForm::apply()
{
    for (PropertyEdit* propertyEdit : m_propertyEdits) {
        propertyEdit->apply();
    }
}

void PropertiesForm::revert()
{
    for (PropertyEdit* propertyEdit : m_propertyEdits) {
        propertyEdit->revert();
    }
}

void PropertiesForm::setupUI()
{
    // Clear UI
    m_propertyEdits.clear();
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
        label->setText("<b>" + QString::fromLocal8Bit(metaObj->className()) + "</b>");
        ui->scrollAreaWidgetContents->layout()->addWidget(label);

        if (metaObj->propertyCount() - 1 > metaObj->propertyOffset()) {

            auto formWidget = new QWidget(ui->scrollAreaWidgetContents);
            ui->scrollAreaWidgetContents->layout()->addWidget(formWidget);
            auto formLayout = new QFormLayout(formWidget);
            formWidget->setLayout(formLayout);
            formLayout->setContentsMargins(0, 0, 0, 0);
            for (int i = metaObj->propertyCount() - 1; i >= metaObj->propertyOffset(); i--) {
                QMetaProperty property = metaObj->property(i);

                QLabel* label = new QLabel(ui->scrollAreaWidgetContents);
                label->setText(QString::fromLocal8Bit(property.typeName()));

                if (property.isReadable() && property.typeId() == QMetaType::QString) {
                    auto lineEdit = new QLineEdit(ui->scrollAreaWidgetContents);
                    lineEdit->setText("AA");
                    formLayout->addRow(QString::fromLocal8Bit(property.name()) + ": ", lineEdit);
                } else if (property.isReadable() && property.typeId() == QMetaType::Float) {
                    auto floatPropertyEdit = new FloatPropertyEdit(m_node, property, ui->scrollAreaWidgetContents);
                    m_propertyEdits.append(floatPropertyEdit);
                    formLayout->addRow(QString::fromLocal8Bit(property.name()) + ": ", floatPropertyEdit);

                    connect(floatPropertyEdit, &PropertyEdit::widgetValueChanged, this, [&]() {
                        bool dirty = false;
                        for (PropertyEdit* propertyEdit : m_propertyEdits) {
                            dirty |= propertyEdit->dirty();
                        }
                        ui->applyButton->setEnabled(dirty);
                        ui->revertButton->setEnabled(dirty);
                    });
                } else {
                    QLabel* label = new QLabel(ui->scrollAreaWidgetContents);
                    label->setText(QString::fromLocal8Bit(property.typeName()));
                    formLayout->addRow(QString::fromLocal8Bit(property.name()) + ": ", label);
                }
            }
        }

        metaObj = metaObj->superClass();
    }
}
