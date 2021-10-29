#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

#include <Qt3DCore/QEntity>

class Application : public QApplication {
    Q_OBJECT
public:
    explicit Application(int& argc, char** argv);

    static Application* instance();

    Qt3DCore::QEntity& rootEntity();

protected:
    void setupScene();

private:
    Qt3DCore::QEntity m_rootEntity;
};

#endif // APPLICATION_H
