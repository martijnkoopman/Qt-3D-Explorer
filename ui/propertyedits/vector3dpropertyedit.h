#ifndef VECTOR3DPROPERTYEDIT_H
#define VECTOR3DPROPERTYEDIT_H

#include "propertyedit.h"

class DoubleEdit;

class Vector3DPropertyEdit : public PropertyEdit {
    Q_OBJECT
public:
    explicit Vector3DPropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent = nullptr);

    QVector3D propertyValue() const;
    QVector3D widgetValue() const;

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
};

#endif // VECTOR3DPROPERTYEDIT_H
