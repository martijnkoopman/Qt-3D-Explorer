#ifndef DOUBLEEDIT_H
#define DOUBLEEDIT_H

#include <QLineEdit>

class QDoubleValidator;

class DoubleEdit : public QLineEdit {
    Q_OBJECT
    Q_PROPERTY(double value READ value WRITE setValue NOTIFY valueChanged)
public:
    explicit DoubleEdit(QWidget* parent = nullptr);

    double value() const;

public slots:
    void setValue(double val);
    void setValueText(const QString& txt);
    void setTop(double t);
    void setBottom(double b);

signals:
    void valueChanged(double val);

private:
    QDoubleValidator* m_validator;
};

#endif // DOUBLEEDIT_H
