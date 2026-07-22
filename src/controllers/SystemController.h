#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H

#include <QObject>
#include <QTimer>

class SystemController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString currentTime READ currentTime NOTIFY currentTimeChanged)

public:
    explicit SystemController(QObject *parent = nullptr);

    QString currentTime() const;

signals:
    void currentTimeChanged();

private slots:
    void updateTime();

private:
    QString m_currentTime;
    QTimer m_timer;
};

#endif
