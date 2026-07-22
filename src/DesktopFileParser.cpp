#include "DesktopFileParser.h"

#include <QDir>
#include <QFile>
#include <QRegularExpression>
#include <QStandardPaths>
#include <QTextStream>

QVector<ApplicationInfo> DesktopFileParser::loadApplications() const
{
    QVector<ApplicationInfo> applications;

    scanDirectory("/usr/share/applications", applications);

    scanDirectory(
        QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation),
        applications);

    return applications;
}

void DesktopFileParser::scanDirectory(
    const QString &path,
    QVector<ApplicationInfo> &applications) const
{
    QDir dir(path);

    const auto files = dir.entryList(
        QStringList() << "*.desktop",
        QDir::Files);

    for (const QString &file : files)
    {
        auto app = parseDesktopFile(dir.filePath(file));

        if (!app.name.isEmpty() && !app.command.isEmpty())
            applications.append(app);
    }
}

ApplicationInfo DesktopFileParser::parseDesktopFile(
    const QString &fileName) const
{
    ApplicationInfo app;

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return app;

    QTextStream in(&file);

    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed();

        if (line.startsWith("Name="))
            app.name = line.mid(5);

        else if (line.startsWith("Icon="))
            app.icon = line.mid(5);

        else if (line.startsWith("Exec="))
        {
            QString exec = line.mid(5);

            exec.remove(QRegularExpression("%[fFuUdDnNickvm]"));

            app.command = exec.trimmed();
        }

        else if (line.startsWith("NoDisplay=true"))
            return ApplicationInfo();

        else if (line.startsWith("Hidden=true"))
            return ApplicationInfo();
    }

    app.id = QFileInfo(fileName).baseName();
    app.favorite = true;

    return app;
}
