#include "quaternionpropertyedit.h"

#include "ui/edits/doubleedit.h"

#include <QFont>
#include <QFrame>
#include <QHBoxLayout>
#include <QQuaternion>

#include <limits>

QuaternionPropertyEdit::QuaternionPropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent)
    : PropertyEdit(obj, prop, parent)
    , m_edit0(new DoubleEdit(this))
    , m_edit1(new DoubleEdit(this))
    , m_edit2(new DoubleEdit(this))
    , m_edit3(new DoubleEdit(this))
{
    m_edit0->setTop(std::numeric_limits<float>::max());
    m_edit0->setBottom(std::numeric_limits<float>::min());
    m_edit1->setTop(std::numeric_limits<float>::max());
    m_edit1->setBottom(std::numeric_limits<float>::min());
    m_edit2->setTop(std::numeric_limits<float>::max());
    m_edit2->setBottom(std::numeric_limits<float>::min());
    m_edit3->setTop(std::numeric_limits<float>::max());
    m_edit3->setBottom(std::numeric_limits<float>::min());

    auto layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    auto line = new QFrame(this);
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);

    layout->addWidget(m_edit0);
    layout->addWidget(m_edit1);
    layout->addWidget(m_edit2);
    layout->addWidget(line);
    layout->addWidget(m_edit3);

    QQuaternion propVal = propertyValue();
    m_edit0->setValue(propVal.x());
    m_edit1->setValue(propVal.y());
    m_edit2->setValue(propVal.z());
    m_edit3->setValue(propVal.scalar());

    connect(m_edit0, &DoubleEdit::valueChanged, this, &QuaternionPropertyEdit::updateUI);
    connect(m_edit1, &DoubleEdit::valueChanged, this, &QuaternionPropertyEdit::updateUI);
    connect(m_edit2, &DoubleEdit::valueChanged, this, &QuaternionPropertyEdit::updateUI);
    connect(m_edit3, &DoubleEdit::valueChanged, this, &QuaternionPropertyEdit::updateUI);
}

QQuaternion QuaternionPropertyEdit::propertyValue() const
{
    return qvariant_cast<QQuaternion>(m_property.read(m_object));
}

QQuaternion QuaternionPropertyEdit::widgetValue() const
{
    return QQuaternion(
        static_cast<float>(m_edit3->value()),
        static_cast<float>(m_edit0->value()),
        static_cast<float>(m_edit1->value()),
        static_cast<float>(m_edit2->value()));
}

void QuaternionPropertyEdit::apply()
{
    m_property.write(m_object, QVariant(widgetValue()));
    updateUI();
}

void QuaternionPropertyEdit::revert()
{
    QQuaternion propVal = propertyValue();
    m_edit0->setValue(propVal.x());
    m_edit1->setValue(propVal.y());
    m_edit2->setValue(propVal.z());
    m_edit3->setValue(propVal.scalar());

    updateUI();
}

bool QuaternionPropertyEdit::dirty()
{
    return propertyValue() != widgetValue();
}

void QuaternionPropertyEdit::updateUI()
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
