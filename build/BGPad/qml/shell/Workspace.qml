import QtQuick

Item {

    Grid {
        anchors.centerIn: parent

        columns: 4
        spacing: 24

        Repeater {
            model: applicationController.model

            delegate: BGTile {
                text: model.name
                enabled: model.favorite

                onClicked: backend.launchApplication(model.command)
            }
        }
    }
}
