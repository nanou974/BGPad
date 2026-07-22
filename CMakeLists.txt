cmake_minimum_required(VERSION 3.16)

project(BGPad VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(bgpad
    src/main.cpp
    src/Backend.cpp
    src/DesktopFileParser.cpp

    src/controllers/SystemController.cpp
    src/controllers/ApplicationController.cpp

    src/models/ApplicationModel.cpp
)

qt_add_qml_module(bgpad
    URI BGPad
    VERSION 1.0

    QML_FILES
        qml/Main.qml

        qml/shell/Shell.qml
        qml/shell/TopBar.qml
        qml/shell/BottomBar.qml
        qml/shell/WorkspaceView.qml
        qml/shell/Workspace.qml

        qml/components/BGButton.qml
        qml/components/BGLabel.qml
        qml/components/BGTile.qml
)

target_include_directories(bgpad PRIVATE
    src
    src/controllers
    src/models
)

target_link_libraries(bgpad
    PRIVATE
        Qt6::Quick
)
