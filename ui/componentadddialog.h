#ifndef COMPONENTADDDIALOG_H
#define COMPONENTADDDIALOG_H

#include <QDialog>

namespace Ui {
class ComponentAddDialog;
}

class ComponentAddDialog : public QDialog {
    Q_OBJECT

public:
    explicit ComponentAddDialog(QWidget* parent = nullptr);
    ~ComponentAddDialog();

private:
    Ui::ComponentAddDialog* ui;
};

#endif // COMPONENTADDDIALOG_H
