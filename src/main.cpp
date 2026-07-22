#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QWindow>

#include "Backend.h"
#include "controllers/SystemController.h"
#include "controllers/ApplicationController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Backend backend;
    SystemController system;
    ApplicationController applicationController;

    engine.rootContext()->setContextProperty("backend", &backend);
    engine.rootContext()->setContextProperty("system", &system);
    engine.rootContext()->setContextProperty("applicationController", &applicationController);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("BGPad", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    if (QWindow *window = qobject_cast<QWindow *>(engine.rootObjects().first()))
        backend.setMainWindow(window);

    return app.exec();
}
