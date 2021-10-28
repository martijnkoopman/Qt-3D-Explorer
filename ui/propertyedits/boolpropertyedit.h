#ifndef BOOLPROPERTYEDIT_H
#define BOOLPROPERTYEDIT_H

#include "propertyedit.h"

class QCheckBox;

class BoolPropertyEdit : public PropertyEdit {
    Q_OBJECT
public:
    explicit BoolPropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent = nullptr);

    bool propertyValue() const;
    bool widgetValue() const;

public slots:
    void apply() override;
    void revert() override;
    bool dirty() override;

protected slots:
    void updateUI();

private:
    QCheckBox* m_checkBox;
};

#endif // BOOLPROPERTYEDIT_H
