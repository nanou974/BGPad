import QtQuick
import QtQuick.Layouts

Rectangle {

    Layout.preferredHeight: 64

    color: "#262626"

    RowLayout {

        anchors.fill: parent

        spacing: 24

        Item {
            Layout.fillWidth: true
        }

        BGButton {
            text: "◀"
        }

        BGButton {
            text: "⌂"
        }

        BGButton {
            text: "≡"
        }

        Item {
            Layout.fillWidth: true
        }
    }
}
