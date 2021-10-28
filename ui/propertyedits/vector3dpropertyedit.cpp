#include "vector3dpropertyedit.h"

#include "ui/edits/doubleedit.h"

#include <QFont>
#include <QHBoxLayout>
#include <QVector3D>

#include <limits>

Vector3DPropertyEdit::Vector3DPropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent)
    : PropertyEdit(obj, prop, parent)
    , m_edit0(new DoubleEdit(this))
    , m_edit1(new DoubleEdit(this))
    , m_edit2(new DoubleEdit(this))
{
    m_edit0->setTop(std::numeric_limits<float>::max());
    m_edit0->setBottom(std::numeric_limits<float>::min());
    m_edit1->setTop(std::numeric_limits<float>::max());
    m_edit1->setBottom(std::numeric_limits<float>::min());
    m_edit2->setTop(std::numeric_limits<float>::max());
    m_edit2->setBottom(std::numeric_limits<float>::min());

    auto layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    layout->addWidget(m_edit0);
    layout->addWidget(m_edit1);
    layout->addWidget(m_edit2);

    QVector3D propVal = propertyValue();
    m_edit0->setValue(propVal.x());
    m_edit1->setValue(propVal.y());
    m_edit2->setValue(propVal.z());

    connect(m_edit0, &DoubleEdit::valueChanged, this, &Vector3DPropertyEdit::updateUI);
    connect(m_edit1, &DoubleEdit::valueChanged, this, &Vector3DPropertyEdit::updateUI);
    connect(m_edit2, &DoubleEdit::valueChanged, this, &Vector3DPropertyEdit::updateUI);
}

QVector3D Vector3DPropertyEdit::propertyValue() const
{
    return qvariant_cast<QVector3D>(m_property.read(m_object));
}

QVector3D Vector3DPropertyEdit::widgetValue() const
{
    return QVector3D(
        static_cast<float>(m_edit0->value()),
        static_cast<float>(m_edit1->value()),
        static_cast<float>(m_edit2->value()));
}

void Vector3DPropertyEdit::apply()
{
    m_property.write(m_object, QVariant(widgetValue()));
    updateUI();
}

void Vector3DPropertyEdit::revert()
{
    QVector3D propVal = propertyValue();
    m_edit0->setValue(propVal.x());
    m_edit1->setValue(propVal.y());
    m_edit2->setValue(propVal.z());

    updateUI();
}

bool Vector3DPropertyEdit::dirty()
{
    return propertyValue() != widgetValue();
}

void Vector3DPropertyEdit::updateUI()
{
    const bool dir = dirty();

    // Set font weight
    QFont font(m_edit0->font());
    font.setBold(dir);
    m_edit0->setFont(font);
    m_edit1->setFont(font);
    m_edit2->setFont(font);

    // Emit signal
    emit widgetValueChanged();
}
