#include "ApplicationModel.h"

ApplicationModel::ApplicationModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int ApplicationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_applications.count();
}

QVariant ApplicationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return {};

    const ApplicationInfo &app = m_applications.at(index.row());

    switch (role)
    {
    case IdRole:
        return app.id;

    case NameRole:
        return app.name;

    case IconRole:
        return app.icon;

    case CommandRole:
        return app.command;

    case FavoriteRole:
        return app.favorite;

    default:
        return {};
    }
}

QHash<int, QByteArray> ApplicationModel::roleNames() const
{
    return {
        { IdRole, "id" },
        { NameRole, "name" },
        { IconRole, "icon" },
        { CommandRole, "command" },
        { FavoriteRole, "favorite" }
    };
}

void ApplicationModel::addApplication(const ApplicationInfo &application)
{
    beginInsertRows(QModelIndex(), m_applications.count(), m_applications.count());
    m_applications.append(application);
    endInsertRows();
}
