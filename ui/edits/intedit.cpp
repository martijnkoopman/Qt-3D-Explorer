#include "intedit.h"

#include <QIntValidator>

IntEdit::IntEdit(QWidget* parent)
    : QLineEdit(parent)
    , m_validator(new QIntValidator(this))
{
    setValidator(m_validator);

    connect(this, &QLineEdit::textChanged, this, &IntEdit::setValueText);
}

int IntEdit::value() const
{
    return text().toInt();
}

void IntEdit::setValue(int val)
{
    QLineEdit::setText(QString::number(val));
}

void IntEdit::setTop(int t)
{
    m_validator->setTop(t);
}

void IntEdit::setBottom(int b)
{
    m_validator->setBottom(b);
}

void IntEdit::setValueText(const QString& txt)
{
    Q_UNUSED(txt)
    emit valueChanged(value());
}
