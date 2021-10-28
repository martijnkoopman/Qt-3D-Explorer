#ifndef QUATERNIONPROPERTYEDIT_H
#define QUATERNIONPROPERTYEDIT_H

#include "propertyedit.h"

class QQuaternion;
class DoubleEdit;

class QuaternionPropertyEdit : public PropertyEdit {
public:
    explicit QuaternionPropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent = nullptr);

    QQuaternion propertyValue() const;
    QQuaternion widgetValue() const;

public slots:
    void apply() override;
    void revert() override;
    bool dirty() override;

protected slots:
    void updateUI();

private:
    DoubleEdit* m_edit0;
    DoubleEdit* m_edit1;
    DoubleEdit* m_edit2;
    DoubleEdit* m_edit3;
};

#endif // QUATERNIONPROPERTYEDIT_H
