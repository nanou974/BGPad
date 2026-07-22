#include "SystemController.h"

#include <QDateTime>

SystemController::SystemController(QObject *parent)
    : QObject(parent)
{
    connect(&m_timer, &QTimer::timeout,
            this, &SystemController::updateTime);

    m_timer.start(1000);

    updateTime();
}

QString SystemController::currentTime() const
{
    return m_currentTime;
}

void SystemController::updateTime()
{
    QString time = QDateTime::currentDateTime().toString("HH:mm");

    if (time != m_currentTime)
    {
        m_currentTime = time;
        emit currentTimeChanged();
    }
}
