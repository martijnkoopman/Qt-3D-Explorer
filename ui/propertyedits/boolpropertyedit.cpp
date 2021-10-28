#include "boolpropertyedit.h"

#include <QCheckBox>
#include <QGridLayout>

BoolPropertyEdit::BoolPropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent)
    : PropertyEdit(obj, prop, parent)
    , m_checkBox(new QCheckBox(this))
{
    auto layout = new QGridLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_checkBox);

    m_checkBox->setChecked(propertyValue());

    connect(m_checkBox, &QCheckBox::toggled, this, &BoolPropertyEdit::updateUI);
}

bool BoolPropertyEdit::propertyValue() const
{
    return m_property.read(m_object).toBool();
}

bool BoolPropertyEdit::widgetValue() const
{
    return m_checkBox->isChecked();
}

void BoolPropertyEdit::apply()
{
    m_property.write(m_object, QVariant(widgetValue()));
    updateUI();
}

void BoolPropertyEdit::revert()
{
    m_checkBox->setChecked(propertyValue());
    updateUI();
}

bool BoolPropertyEdit::dirty()
{
    return propertyValue() != widgetValue();
}

void BoolPropertyEdit::updateUI()
{
    const bool dir = dirty();

    // Set font weight
    QFont font(m_checkBox->font());
    font.setBold(dir);
    m_checkBox->setFont(font);

    // Emit signal
    emit widgetValueChanged();
}
