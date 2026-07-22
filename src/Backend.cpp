#include "Backend.h"

#include <QProcess>
#include <QWindow>

Backend::Backend(QObject *parent)
    : QObject(parent)
{
}

void Backend::setMainWindow(QWindow *window)
{
    m_mainWindow = window;
}

void Backend::launchApplication(const QString &command)
{
    if (command.isEmpty())
        return;

    if (m_mainWindow)
        m_mainWindow->showMinimized();

    QProcess::startDetached(command);
}
