#ifndef PROPERTYEDIT_H
#define PROPERTYEDIT_H

#include <QMetaProperty>
#include <QWidget>

class PropertyEdit : public QWidget {
    Q_OBJECT
    Q_PROPERTY(QObject* object READ object)
    Q_PROPERTY(QMetaProperty property READ property)
public:
    explicit PropertyEdit(QObject* obj, QMetaProperty prop, QWidget* parent = nullptr);

    QObject* object() const;
    QMetaProperty property() const;

public slots:
    virtual void apply() = 0;
    virtual void revert() = 0;
    virtual bool dirty() = 0;

signals:
    void widgetValueChanged();

protected:
    QObject* m_object;
    QMetaProperty m_property;
};

#endif // PROPERTYEDIT_H
