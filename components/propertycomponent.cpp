#include "propertycomponent.h"

PropertyComponent::PropertyComponent(QNode* parent)
    : Qt3DCore::QComponent(parent)
    , m_bool(false)
    , m_double(0)
    , m_enum(PropertyEnum::Value1)
    , m_float(0)
    , m_int(0)
    , m_matrix4x4()
    , m_quaternion()
    , m_string("string")
    , m_vector3D()
{
}

// Getters

bool PropertyComponent::boolProperty() const
{
    return m_bool;
}

double PropertyComponent::doubleProperty() const
{
    return m_double;
}

PropertyComponent::PropertyEnum PropertyComponent::enumProperty() const
{
    return m_enum;
}

float PropertyComponent::floatProperty() const
{
    return m_float;
}

int PropertyComponent::intProperty() const
{
    return m_int;
}

const QMatrix4x4& PropertyComponent::matrix4x4Property() const
{
    return m_matrix4x4;
}

const QQuaternion& PropertyComponent::quaternionProperty() const
{
    return m_quaternion;
}

const QString& PropertyComponent::stringProperty() const
{
    return m_string;
}

const QVector3D& PropertyComponent::vector3DProperty() const
{
    return m_vector3D;
}

// Setters

void PropertyComponent::setBoolProperty(bool property)
{
    if (property == m_bool) {
        return;
    }

    m_bool = property;

    emit boolPropertyChanged(m_bool);
}

void PropertyComponent::setDoubleProperty(double property)
{
    if (property == m_double) {
        return;
    }

    m_double = property;

    emit doublePropertyChanged(m_double);
}

void PropertyComponent::setEnumProperty(PropertyEnum property)
{
    if (property == m_enum) {
        return;
    }

    m_enum = property;

    emit enumPropertyChanged(m_enum);
}

void PropertyComponent::setFloatProperty(float property)
{
    if (property == m_float) {
        return;
    }

    m_float = property;

    emit floatPropertyChanged(m_float);
}

void PropertyComponent::setIntProperty(int property)
{
    if (property == m_int) {
        return;
    }

    m_int = property;

    emit intPropertyChanged(m_int);
}

void PropertyComponent::setMatrix4x4Property(const QMatrix4x4& property)
{
    if (property == m_matrix4x4) {
        return;
    }

    m_matrix4x4 = property;

    emit matrix4x4PropertyChanged(m_matrix4x4);
}

void PropertyComponent::setQuaternionProperty(const QQuaternion& property)
{
    if (property == m_quaternion) {
        return;
    }

    m_quaternion = property;

    emit quaternionPropertyChanged(m_quaternion);
}

void PropertyComponent::setStringProperty(const QString& property)
{
    if (property == m_string) {
        return;
    }

    m_string = property;

    emit stringPropertyChanged(m_string);
}

void PropertyComponent::setVector3DProperty(const QVector3D& property)
{
    if (property == m_vector3D) {
        return;
    }

    m_vector3D = property;

    emit vector3DPropertyChanged(m_vector3D);
}
