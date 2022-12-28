import QtQuick 2.15

import QtQuick.Window
import QtQuick.Layouts

Item {
    id: root;
    visible: true;
    height: 80 * Screen.desktopAvailableHeight / 100;
    width: 80 * Screen.desktopAvailableWidth / 100;
//    minHeight: 10 * Screen.desktopAvailableWidth / 100;
//    minimumWidth: 40 * Screen.desktopAvailableWidth / 100;

    ColumnLayout {
        anchors.fill: parent;
        anchors.margins: 2;
        spacing: 1;

        Rectangle {
            color: "red";
            Layout.fillWidth: true;
            Layout.preferredHeight: 50;
            Layout.alignment: Qt.AlignCenter
        }

        Rectangle {
            color: "blue";
            Layout.fillWidth: true;
            Layout.fillHeight: true;
            Layout.alignment: Qt.AlignCenter

        }

        Rectangle {
            color: "black";
            Layout.fillWidth: true;
            Layout.preferredHeight: 35;
            Layout.alignment: Qt.AlignCenter
        }
    }
}
