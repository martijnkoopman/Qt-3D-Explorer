#ifndef URLPROPERTYEDIT_H
#define URLPROPERTYEDIT_H

#include "propertyedit.h"

class QLineEdit;

class UrlPropertyEdit : public PropertyEdit {
    Q_OBJECT
public:
    explicit UrlPropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent = nullptr);

    QUrl propertyValue() const;
    QUrl widgetValue() const;

public slots:
    void apply() override;
    void revert() override;
    bool dirty() override;

protected slots:
    void updateUI();

private:
    QLineEdit* m_edit;
};

#endif // URLPROPERTYEDIT_H
