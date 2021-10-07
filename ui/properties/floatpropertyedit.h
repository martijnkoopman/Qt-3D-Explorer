#ifndef FLOATPROPERTYEDIT_H
#define FLOATPROPERTYEDIT_H

#include "propertyedit.h"

class DoubleEdit;

class FloatPropertyEdit : public PropertyEdit {
    Q_OBJECT
public:
    explicit FloatPropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent = nullptr);

    float propertyValue() const;
    float widgetValue() const;

public slots:
    void apply() override;
    void revert() override;
    bool dirty() override;

protected slots:
    void updateUI();

private:
    DoubleEdit* m_edit;
};

#endif // FLOATPROPERTYEDIT_H
