#include "doubleedit.h"

#include <QDoubleValidator>

DoubleEdit::DoubleEdit(QWidget* parent)
    : QLineEdit(parent)
    , m_validator(new QDoubleValidator(this))
{
    setValidator(m_validator);

    connect(this, &QLineEdit::textChanged, this, &DoubleEdit::setValueText);
}

double DoubleEdit::value() const
{
    return text().toDouble();
}

void DoubleEdit::setValue(double val)
{
    QLineEdit::setText(QString::number(val, 'f'));
}

void DoubleEdit::setValueText(const QString& txt)
{
    Q_UNUSED(txt)
    emit valueChanged(value());
}

void DoubleEdit::setTop(double t)
{
    m_validator->setTop(t);
}

void DoubleEdit::setBottom(double b)
{
    m_validator->setBottom(b);
}
