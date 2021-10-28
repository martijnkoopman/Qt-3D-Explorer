#ifndef PROPERTYCOMPONENT_H
#define PROPERTYCOMPONENT_H

#include <Qt3DCore/QComponent>

#include <QMatrix4x4>
#include <QQuaternion>
#include <QString>
#include <QVector3D>

class PropertyComponent : public Qt3DCore::QComponent {
    Q_OBJECT
    Q_PROPERTY(bool boolProperty READ boolProperty WRITE setBoolProperty NOTIFY boolPropertyChanged)
    Q_PROPERTY(double doubleProperty READ doubleProperty WRITE setDoubleProperty NOTIFY doublePropertyChanged)
    Q_PROPERTY(PropertyEnum enumProperty READ enumProperty WRITE setEnumProperty NOTIFY enumPropertyChanged)
    Q_PROPERTY(float floatProperty READ floatProperty WRITE setFloatProperty NOTIFY floatPropertyChanged)
    Q_PROPERTY(int intProperty READ intProperty WRITE setIntProperty NOTIFY intPropertyChanged)
    Q_PROPERTY(QMatrix4x4 matrix4x4Property READ matrix4x4Property WRITE setMatrix4x4Property NOTIFY matrix4x4PropertyChanged)
    Q_PROPERTY(QQuaternion quaternionProperty READ quaternionProperty WRITE setQuaternionProperty NOTIFY quaternionPropertyChanged)
    Q_PROPERTY(QString stringProperty READ stringProperty WRITE setStringProperty NOTIFY stringPropertyChanged)
    Q_PROPERTY(QVector3D vector3DProperty READ vector3DProperty WRITE setVector3DProperty NOTIFY vector3DPropertyChanged)

public:
    enum PropertyEnum {
        Value1,
        Value_2,
        VALUE3,
        VALUE_4
    };
    Q_ENUM(PropertyEnum)

    explicit PropertyComponent(QNode* parent = nullptr);

    // Getters
    bool boolProperty() const;
    double doubleProperty() const;
    PropertyEnum enumProperty() const;
    float floatProperty() const;
    int intProperty() const;
    const QMatrix4x4& matrix4x4Property() const;
    const QQuaternion& quaternionProperty() const;
    const QString& stringProperty() const;
    const QVector3D& vector3DProperty() const;

public slots:
    void setBoolProperty(bool property);
    void setDoubleProperty(double property);
    void setEnumProperty(PropertyEnum property);
    void setFloatProperty(float property);
    void setIntProperty(int property);
    void setMatrix4x4Property(const QMatrix4x4& property);
    void setQuaternionProperty(const QQuaternion& property);
    void setStringProperty(const QString& property);
    void setVector3DProperty(const QVector3D& property);

signals:
    void boolPropertyChanged(bool property);
    void doublePropertyChanged(double property);
    void enumPropertyChanged(PropertyEnum property);
    void floatPropertyChanged(float property);
    void intPropertyChanged(int property);
    void matrix4x4PropertyChanged(const QMatrix4x4& property);
    void quaternionPropertyChanged(const QQuaternion& property);
    void stringPropertyChanged(const QString& property);
    void vector3DPropertyChanged(const QVector3D& property);

private:
    bool m_bool;
    double m_double;
    PropertyEnum m_enum;
    float m_float;
    int m_int;
    QMatrix4x4 m_matrix4x4;
    QQuaternion m_quaternion;
    QString m_string;
    QVector3D m_vector3D;
};

#endif // PROPERTYCOMPONENT_H
