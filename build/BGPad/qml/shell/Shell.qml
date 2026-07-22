import QtQuick
import QtQuick.Layouts

Item {

    Rectangle {
        anchors.fill: parent
        color: "#181818"
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        TopBar {
            Layout.fillWidth: true
        }

        WorkspaceView {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        BottomBar {
            Layout.fillWidth: true
        }
    }
}
