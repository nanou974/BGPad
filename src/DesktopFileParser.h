#ifndef DESKTOPFILEPARSER_H
#define DESKTOPFILEPARSER_H

#include <QVector>

#include "models/ApplicationInfo.h"

class DesktopFileParser
{
public:
    QVector<ApplicationInfo> loadApplications() const;

private:
    void scanDirectory(const QString &path,
                       QVector<ApplicationInfo> &applications) const;

    ApplicationInfo parseDesktopFile(const QString &fileName) const;
};

#endif
