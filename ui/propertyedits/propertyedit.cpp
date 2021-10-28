#include "propertyedit.h"

PropertyEdit::PropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent)
    : QWidget(parent)
    , m_object(obj)
    , m_property(prop)
{
}

QObject* PropertyEdit::object() const
{
    return m_object;
}

QMetaProperty PropertyEdit::property() const
{
    return m_property;
}
