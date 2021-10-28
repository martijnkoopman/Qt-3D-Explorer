#ifndef INTEDIT_H
#define INTEDIT_H

#include <QLineEdit>

class QIntValidator;

class IntEdit : public QLineEdit {
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
public:
    explicit IntEdit(QWidget* parent = nullptr);

    int value() const;

public slots:
    void setValue(int val);
    void setTop(int t);
    void setBottom(int b);

signals:
    void valueChanged(int val);

protected slots:
    void setValueText(const QString& txt);

private:
    QIntValidator* m_validator;
};

#endif // INTEDIT_H
