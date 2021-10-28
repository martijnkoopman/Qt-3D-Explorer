#ifndef ENUMPROPERTYEDIT_H
#define ENUMPROPERTYEDIT_H

#include "propertyedit.h"

class QComboBox;

class EnumPropertyEdit : public PropertyEdit {
    Q_OBJECT
public:
    explicit EnumPropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent = nullptr);

    QString propertyValue() const;
    QString widgetValue() const;

public slots:
    void apply();
    void revert();
    bool dirty();

protected slots:
    void updateUI();

private:
    QComboBox* m_comboBox;
};

#endif // ENUMPROPERTYEDIT_H
