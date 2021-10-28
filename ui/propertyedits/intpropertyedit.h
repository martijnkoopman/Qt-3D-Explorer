#ifndef INTPROPERTYEDIT_H
#define INTPROPERTYEDIT_H

#include "propertyedit.h"

class IntEdit;

class IntPropertyEdit : public PropertyEdit {
    Q_OBJECT
public:
    explicit IntPropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent = nullptr);

    int propertyValue() const;
    int widgetValue() const;

public slots:
    void apply() override;
    void revert() override;
    bool dirty() override;

protected slots:
    void updateUI();

private:
    IntEdit* m_edit;
};

#endif // INTPROPERTYEDIT_H
