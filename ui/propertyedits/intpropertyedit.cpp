#include "intpropertyedit.h"

#include "ui/edits/intedit.h"

#include <QFont>
#include <QGridLayout>

#include <limits>

IntPropertyEdit::IntPropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent)
    : PropertyEdit(obj, prop, parent)
    , m_edit(new IntEdit(this))
{
    m_edit->setTop(std::numeric_limits<int>::max());
    m_edit->setBottom(std::numeric_limits<int>::min());

    auto layout = new QGridLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_edit);

    m_edit->setValue(propertyValue());

    connect(m_edit, &IntEdit::valueChanged, this, &IntPropertyEdit::updateUI);
}

int IntPropertyEdit::propertyValue() const
{
    return m_property.read(m_object).toInt();
}

int IntPropertyEdit::widgetValue() const
{
    return static_cast<int>(m_edit->value());
}

void IntPropertyEdit::apply()
{
    m_property.write(m_object, QVariant(widgetValue()));
    updateUI();
}

void IntPropertyEdit::revert()
{
    m_edit->setValue(static_cast<double>(propertyValue()));
    updateUI();
}

bool IntPropertyEdit::dirty()
{
    return propertyValue() != widgetValue();
}

void IntPropertyEdit::updateUI()
{
    const bool dir = dirty();

    // Set font weight
    QFont font(m_edit->font());
    font.setBold(dir);
    m_edit->setFont(font);

    // Emit signal
    emit widgetValueChanged();
}
