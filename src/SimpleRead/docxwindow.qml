import QtQuick 2.15

import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls

Item {
    id: root;
    visible: true;
    height: 80 * Screen.desktopAvailableHeight / 100;
    width: 80 * Screen.desktopAvailableWidth / 100;

    ColumnLayout {
        anchors.fill: parent;
        anchors.margins: 2;
        spacing: 1;

        Rectangle {
            id: barMenu

            color: "red";
            Layout.fillWidth: true;
            Layout.preferredHeight: 50;
            Layout.alignment: Qt.AlignCenter

            RowLayout {
                anchors.fill: parent;
                anchors.margins: 2;
                spacing: 1;

                ListView {
                    orientation: ListView.Horizontal

                    model: ListModel {
                        id: barModel

                        property var actions: {
                            "lock_edit": "",
                            "unlock_edit": "",
                            "save": ""
                        }

                        ListElement {
                            name: "lock_edit"
                            icon: "images/lock_edit.png"
                            action: "lock_edit"
                            enabled: true
                        }

                        ListElement {
                            name: "unlock_edit"
                            icon: "images/unlock_edit.png"
                            action: "unlock_edit"
                            enabled: true
                        }

                        ListElement {
                            name: "save"
                            icon: "images/unlock_edit.png"
                            action: "save"
                            enabled: false
                        }
                    }

                    delegate: Rectangle {
                        anchors.fill: parent;

//                        Layout.preferredWidth: 5 * barMenu.width / 100;
//                        Layout.fillHeight: true;
                        Layout.alignment: Qt.AlignLeft

                        Button {
                            anchors.fill: parent;
                            Layout.fillWidth: true
                            Layout.fillHeight: true;
                            Layout.alignment: Qt.AlignRight
                            icon.source: model.icon;

                            Text{
//                                text: editField.enabled ? qsTr("Lock edit") : qsTr("Unlock edit");
//                                color: "red";
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
//                            onClicked: {
//                                editField.enabled = !editField.enabled;
//                            }
                        }
                    }
                }

//                Rectangle {
//                    color: "yellow";
//                    Layout.preferredWidth: 5 * bottomMenu.width / 100;
//                    Layout.fillHeight: true;
//                    Layout.alignment: Qt.AlignLeft

//                    Button {
//                        Text{
//                            text: editField.enabled ? qsTr("Lock edit") : qsTr("Unlock edit");
//                            color: "red";
//                            anchors.verticalCenter: parent.verticalCenter
//                            anchors.horizontalCenter: parent.horizontalCenter
//                        }

//                        Layout.preferredWidth: 10 * scaleMenu.width / 100;
//                        Layout.fillHeight: true;
//                        Layout.alignment: Qt.AlignRight
//                        onClicked: {
//                            editField.enabled = !editField.enabled;
//                        }
//                    }
//                }

//                Rectangle {
//                    color: "green";
//                    Layout.preferredWidth: 5 * bottomMenu.width / 100;
//                    Layout.fillHeight: true;
//                    Layout.alignment: Qt.AlignLeft

//                    Button {
//                        Text{
//                            text: qsTr("Save");
//                            color: "red";
//                            anchors.verticalCenter: parent.verticalCenter
//                            anchors.horizontalCenter: parent.horizontalCenter
//                        }

//                        Layout.preferredWidth: 10 * scaleMenu.width / 100;
//                        Layout.fillHeight: true;
//                        Layout.alignment: Qt.AlignRight
//                        onClicked: {
//                            DOCXWindow.onSave();
//                        }
//                    }
//                }
            }
        }

        ScrollView{
            Layout.fillWidth: true;
            Layout.fillHeight: true;
            clip: true;

            ScrollBar.vertical.policy: ScrollBar.AlwaysOn;
            ScrollBar.vertical.visible: ScrollBar.vertical.size < 1;

            ScrollBar.horizontal.policy: ScrollBar.AlwaysOn;
            ScrollBar.horizontal.visible: ScrollBar.horizontal.size < 1;
            TextArea {
                id: editField;
                text: DOCXWindow.onReadText();
                color: "blue";
                focus: true;
                font.pointSize: 24;
                wrapMode: TextEdit.WrapAnywhere;
                selectByMouse: true;
                Layout.fillWidth: true;
                Layout.fillHeight: true;
                Layout.alignment: Qt.AlignCenter;
                enabled: true;
                onTextChanged: {
                    console.log("Text changed", editField.cursorPosition);
                }
            }
        }

        Rectangle {
            id: bottomMenu;
            Layout.fillWidth: true;
            Layout.preferredHeight: 35;
            Layout.alignment: Qt.AlignCenter

            RowLayout {
                anchors.fill: parent;
                anchors.margins: 2;
                spacing: 1;

                Rectangle {
                    color: "yellow";
                    Layout.preferredWidth: 50 * bottomMenu.width / 100;
                    Layout.fillHeight: true;
                    Layout.alignment: Qt.AlignLeft
                }

                Rectangle {
                    id: scaleMenu;
                    Layout.preferredWidth: 50 * bottomMenu.width / 100;
                    Layout.fillHeight: true;
                    Layout.alignment: Qt.AlignLeft

                    RowLayout {
                        anchors.fill: parent;
                        anchors.margins: 2;
                        spacing: 1;

                        Button {
                            Text{
                                text: "-";
                                color: "red";
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.horizontalCenter: parent.horizontalCenter
                            }

                            Layout.preferredWidth: 10 * scaleMenu.width / 100;
                            Layout.fillHeight: true;
                            Layout.alignment: Qt.AlignRight
                            onClicked: {
                                editField.font.pointSize -= 1;
                            }
                        }

                        Button {
                            Text{
                                text: "+";
                                color: "red";
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.horizontalCenter: parent.horizontalCenter
                            }

                            Layout.preferredWidth: 10 * scaleMenu.width / 100;
                            Layout.fillHeight: true;
                            Layout.alignment: Qt.AlignRight
                            onClicked: {
                                editField.font.pointSize += 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
