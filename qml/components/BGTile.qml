import QtQuick

Rectangle {
    id: root

    property alias text: label.text
    property url iconSource: ""
    property bool enabled: true

    signal clicked()

    width: 220
    height: 140

    radius: 12

    color: mouseArea.pressed ? "#505050"
          : mouseArea.containsMouse ? "#3a3a3a"
          : "#2b2b2b"

    border.color: "#505050"
    border.width: 1

    Column {
        anchors.centerIn: parent
        spacing: 12

        Image {
            width: 64
            height: 64

            source: root.iconSource
            visible: source !== ""

            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: label

            anchors.horizontalCenter: parent.horizontalCenter

            color: "white"
            font.pixelSize: 24

            horizontalAlignment: Text.AlignHCenter
        }
    }

    MouseArea {
        id: mouseArea

        anchors.fill: parent

        enabled: root.enabled
        hoverEnabled: true

        onClicked: root.clicked()
    }
}
