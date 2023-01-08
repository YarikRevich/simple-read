import QtQuick 2.15

import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import Qt.labs.qmlmodels 1.0

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
            color: "red";
            Layout.fillWidth: true;
            Layout.preferredHeight: 50;
            Layout.alignment: Qt.AlignCenter

            RowLayout {
                anchors.fill: parent;
                anchors.margins: 2;
                spacing: 1;

                Rectangle {
                    color: "yellow";
                    Layout.preferredWidth: 5 * bottomMenu.width / 100;
                    Layout.fillHeight: true;
                    Layout.alignment: Qt.AlignLeft

                    Button {
                        Text{
                            text: tableField.enabled ? qsTr("Lock edit") : qsTr("Unlock edit");
                            color: "red";
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                        }

                        Layout.preferredWidth: 10 * scaleMenu.width / 100;
                        Layout.fillHeight: true;
                        Layout.alignment: Qt.AlignRight
                        onClicked: {
                            editField.enabled = !editField.enabled;
                        }
                    }
                }

                Rectangle {
                    color: "green";
                    Layout.preferredWidth: 5 * bottomMenu.width / 100;
                    Layout.fillHeight: true;
                    Layout.alignment: Qt.AlignLeft

                    Button {
                        Text{
                            text: qsTr("Save");
                            color: "red";
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                        }

                        Layout.preferredWidth: 10 * scaleMenu.width / 100;
                        Layout.fillHeight: true;
                        Layout.alignment: Qt.AlignRight
                        onClicked: {
                            DOCXWindow.onSave();
                        }
                    }
                }
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

            TableView {
                id: tableField;
                anchors.fill: parent
                columnSpacing: 1
                rowSpacing: 1
                clip: true

                property bool loaded: false;

                model: TableModel {
                    id: tableModel;

                    TableModelColumn {
                        display: "name"
                    }

                    TableModelColumn {
                        display: "color"
                    }

//                    rows: [
//                        {
//                            "name": "cat",
//                            "color": "black"
//                        },
//                        {
//                            "name": "dog",
//                            "color": "brown"
//                        },
//                        {
//                            "name": "bird",
//                            "color": "white"
//                        }
//                    ]
                }

                delegate: Rectangle {
                            implicitWidth: 100
                            implicitHeight: 100
                            border.width: 1

                            TextEdit {
                                text: display
                                anchors.centerIn: parent
                                onTextChanged: {
                                    if (tableField.loaded){
                                        const ix = tableModel.index(0, 0);
                                        tableModel.setData(ix, "display", "Yaroslav")
//                                        console.log(display);

//                                        console.log(TextEdit.text);
                                    }
                                }
                            }
                }

                Component.onCompleted: {
                    tableField.loaded = true;

//                    tableModel.insertColumn("name");
//                    tableModel.insertColumn("color");
                    tableModel.appendRow({
                                             "name": "Yaroslav",
                                             "color": "Jjjk",
                                         })
                }
            }
//            TextArea {
//                id: editField;
//                text: CSVWindow.onReadText();
//                color: "blue";
//                focus: true;
//                font.pointSize: 24;
//                wrapMode: TextEdit.WrapAnywhere;
//                selectByMouse: true;
//                Layout.fillWidth: true;
//                Layout.fillHeight: true;
//                Layout.alignment: Qt.AlignCenter;
//                enabled: true;

//            }
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
//                                tableField.font.pointSize -= 1;
                                tableField.height -= 1;
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
                                tableField.height += 1;
//                                tableField.font.pointSize += 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
