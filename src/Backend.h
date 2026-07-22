#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

class QWindow;

class Backend : public QObject
{
    Q_OBJECT

public:
    explicit Backend(QObject *parent = nullptr);

    void setMainWindow(QWindow *window);

    Q_INVOKABLE void launchApplication(const QString &command);

private:
    QWindow *m_mainWindow = nullptr;
};

#endif
