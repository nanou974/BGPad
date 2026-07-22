#ifndef APPLICATIONINFO_H
#define APPLICATIONINFO_H

#include <QString>

struct ApplicationInfo
{
    QString id;
    QString name;
    QString icon;
    QString command;
    bool favorite;
};

#endif
