#include "floatpropertyedit.h"

#include "ui/doubleedit.h"

#include <QFont>
#include <QGridLayout>

#include <limits>

FloatPropertyEdit::FloatPropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent)
    : PropertyEdit(obj, prop, parent)
    , m_edit(new DoubleEdit(this))
{
    m_edit->setTop(std::numeric_limits<float>::max());
    m_edit->setBottom(std::numeric_limits<float>::min());

    auto layout = new QGridLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_edit);

    m_edit->setValue(propertyValue());

    connect(m_edit, &DoubleEdit::valueChanged, this, &FloatPropertyEdit::updateUI);
}

float FloatPropertyEdit::propertyValue() const
{
    return m_property.read(m_object).toFloat();
}

float FloatPropertyEdit::widgetValue() const
{
    return static_cast<double>(m_edit->value());
}

void FloatPropertyEdit::apply()
{
    m_property.write(m_object, QVariant(widgetValue()));
    updateUI();
}

void FloatPropertyEdit::revert()
{
    m_edit->setValue(static_cast<double>(propertyValue()));
    updateUI();
}

bool FloatPropertyEdit::dirty()
{
    return propertyValue() != widgetValue();
}

void FloatPropertyEdit::updateUI()
{
    const bool dir = dirty();

    // Set font weight
    QFont font(m_edit->font());
    font.setBold(dir);
    m_edit->setFont(font);

    // Emit signal
    emit widgetValueChanged();
}
