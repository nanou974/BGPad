import QtQuick
import QtQuick.Layouts

Rectangle {

    Layout.preferredHeight: 48

    color: "#262626"

    RowLayout {

        anchors.fill: parent
        anchors.leftMargin: 16
        anchors.rightMargin: 16

        Text {
            text: "Applications"
            color: "white"
            font.pixelSize: 20
        }

        Item {
            Layout.fillWidth: true
        }

        Text {
            text: system.currentTime
            color: "white"
            font.pixelSize: 18
        }
    }
}
