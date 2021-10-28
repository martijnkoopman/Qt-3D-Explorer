#include "enumpropertyedit.h"

#include <QComboBox>
#include <QGridLayout>

EnumPropertyEdit::EnumPropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent)
    : PropertyEdit(obj, prop, parent)
    , m_comboBox(new QComboBox(this))
{
    auto layout = new QGridLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_comboBox);

    QMetaEnum metaEnum = prop.enumerator();
    for (int i = 0; i < metaEnum.keyCount(); i++) {
        m_comboBox->addItem(metaEnum.key(i));
    }

    m_comboBox->setCurrentText(propertyValue());

    connect(m_comboBox, &QComboBox::currentTextChanged, this, &EnumPropertyEdit::updateUI);
}

QString EnumPropertyEdit::propertyValue() const
{
    QMetaEnum metaEnum = m_property.enumerator();

    bool ok = false;
    int value = m_property.read(m_object).toInt(&ok);
    if (ok) {
        return QString(metaEnum.valueToKey(value));
    }

    return QString();
}

QString EnumPropertyEdit::widgetValue() const
{
    return m_comboBox->currentText();
}

void EnumPropertyEdit::apply()
{
    QMetaEnum metaEnum = m_property.enumerator();
    bool ok = false;
    int key = metaEnum.keyToValue(widgetValue().toStdString().c_str(), &ok);
    if (ok) {
        m_property.write(m_object, QVariant(key));
    }
    updateUI();
}

void EnumPropertyEdit::revert()
{
    m_comboBox->setCurrentText(propertyValue());
    updateUI();
}

bool EnumPropertyEdit::dirty()
{
    return propertyValue() != widgetValue();
}

void EnumPropertyEdit::updateUI()
{
    const bool dir = dirty();

    // Set font weight
    QFont font(m_comboBox->font());
    font.setBold(dir);
    m_comboBox->setFont(font);

    // Emit signal
    emit widgetValueChanged();
}
