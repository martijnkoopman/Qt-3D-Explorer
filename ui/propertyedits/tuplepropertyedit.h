#ifndef TUPLEPROPERTYEDIT_H
#define TUPLEPROPERTYEDIT_H

#include "ipropertyedit.h"

#include <QMetaProperty>
#include <QWidget>
#include <qvariant.h>

#include <array>
#include <cstddef>

class DoubleEdit;

template <class T, size_t N>
class TuplePropertyEdit : public IPropertyEdit {
public:
    explicit TuplePropertyEdit(QObject* obj, QMetaProperty prop)
        : m_object(obj)
        , m_property(prop)
    {
    }

    T propertyValue() const
    {
        return qvariant_cast<T>(m_property.read(m_object));
    }

    T widgetValue() const
    {
        return T();
    }

    void apply() override
    {
        m_property.write(m_object, QVariant(widgetValue()));
        updateUI();
    }

    void revert() override
    {
        T propVal = propertyValue();
        m_edit0->setValue(propVal.x());
        m_edit1->setValue(propVal.y());
        m_edit2->setValue(propVal.z());

        updateUI();
    }

    bool dirty() override
    {
        return propertyValue() != widgetValue();
    }

protected:
    void updateUI()
    {
        const bool dir = dirty();

        // Set font weight
        QFont font(m_edit0->font());
        font.setBold(dir);
        m_edit0->setFont(font);
        m_edit1->setFont(font);
        m_edit2->setFont(font);

        // Emit signal
        emitSignal();
    }

    QObject* m_object;
    QMetaProperty m_property;

private:
    std::array<DoubleEdit*, N> m_edits;
};

#endif // TUPLEPROPERTYEDIT_H
