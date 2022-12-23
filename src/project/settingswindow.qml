import QtQuick 2.15

import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls

Item {
    id: root;
    focus: true;
    visible: true;
    height: 55 * Screen.desktopAvailableHeight / 100;
    width: 30 * Screen.desktopAvailableWidth / 100;


    RowLayout {
        id: layout;
        anchors.fill: parent;
        anchors.centerIn: parent;
        anchors.margins: 2;
        spacing: 1;

        Rectangle {
            color: "red";
            Layout.fillHeight: true;
            Layout.preferredWidth: 30 * root.width / 100;
            Layout.alignment: Qt.AlignCenter

        }

        Rectangle {
            color: "blue";
            Layout.fillWidth: true;
            Layout.fillHeight: true;
            Layout.alignment: Qt.AlignCenter
        }
    }
}
