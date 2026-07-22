#include "ApplicationController.h"

#include "../DesktopFileParser.h"

ApplicationController::ApplicationController(QObject *parent)
    : QObject(parent)
{
    DesktopFileParser parser;

    const auto applications = parser.loadApplications();

    for (const auto &app : applications)
        m_model.addApplication(app);
}

ApplicationModel *ApplicationController::model()
{
    return &m_model;
}
