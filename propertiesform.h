#ifndef PROPERTIESFORM_H
#define PROPERTIESFORM_H

#include <QWidget>

#include <Qt3DCore/QNode>

namespace Ui {
class PropertiesForm;
}

class PropertiesForm : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(Qt3DCore::QNode* node READ node WRITE setNode NOTIFY nodeChanged)
public:
    explicit PropertiesForm(QWidget *parent = nullptr);
    ~PropertiesForm();

    Qt3DCore::QNode* node() const;

public slots:
    void setNode(Qt3DCore::QNode* n);

signals:
    void nodeChanged(Qt3DCore::QNode* n);

protected:
    void setupUI();

private:
    Ui::PropertiesForm* ui;

    Qt3DCore::QNode* m_node;
};

#endif // PROPERTIESFORM_H
