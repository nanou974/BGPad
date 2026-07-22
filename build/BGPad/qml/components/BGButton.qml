import QtQuick
import QtQuick.Controls

Button {

    property color backgroundColor: "#2d2d2d"
    property color hoverColor: "#3a3a3a"
    property color textColor: "white"

    implicitWidth: 220
    implicitHeight: 52

    contentItem: Text {
        text: parent.text
        color: parent.textColor
        font.pixelSize: 18
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    background: Rectangle {
        radius: 8
        color: parent.hovered ? parent.hoverColor : parent.backgroundColor
    }

}
