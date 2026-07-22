#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <QObject>

#include "../models/ApplicationModel.h"

class ApplicationController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(ApplicationModel *model READ model CONSTANT)

public:
    explicit ApplicationController(QObject *parent = nullptr);

    ApplicationModel *model();

private:
    ApplicationModel m_model;
};

#endif
