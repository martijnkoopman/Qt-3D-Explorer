#include "urlpropertyedit.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QUrl>

UrlPropertyEdit::UrlPropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent)
    : PropertyEdit(obj, prop, parent)
    , m_edit(new QLineEdit(this))
{
    m_edit->setSizePolicy(QSizePolicy::Policy::Expanding, m_edit->sizePolicy().verticalPolicy());

    auto layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    layout->addWidget(m_edit);

    QUrl propVal = propertyValue();
    m_edit->setText(propVal.toString());

    connect(m_edit, &QLineEdit::textChanged, this, &UrlPropertyEdit::updateUI);
}

QUrl UrlPropertyEdit::propertyValue() const
{
    return qvariant_cast<QUrl>(m_property.read(m_object));
}

QUrl UrlPropertyEdit::widgetValue() const
{
    return QUrl(m_edit->text());
}

void UrlPropertyEdit::apply()
{
    m_property.write(m_object, QVariant(widgetValue()));
    updateUI();
}

void UrlPropertyEdit::revert()
{
    QUrl propVal = propertyValue();
    m_edit->setText(propVal.toString());

    updateUI();
}

bool UrlPropertyEdit::dirty()
{
    return propertyValue() != widgetValue();
}

void UrlPropertyEdit::updateUI()
{
    const bool dir = dirty();

    // Set font weight
    QFont font(m_edit->font());
    font.setBold(dir);
    m_edit->setFont(font);

    // Emit signal
    emit widgetValueChanged();
}
