import QtQuick 2.15

import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import "storage.js" as Storage

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

            color: "#D9D9D9";
            Layout.fillWidth: true;
            Layout.preferredHeight: 10 * parent.height / 100;
            Layout.alignment: Qt.AlignCenter;

            ListView {
                anchors.fill: parent;
                orientation: ListView.Horizontal;
                anchors.verticalCenter: parent.verticalCenter;
                anchors.horizontalCenter: parent.horizontalCenter;

                spacing: 1;
                clip: true;

                model: ListModel {
                    id: barModel;

                    function getElementByName(name){
                        for (let i = 0; i < barModel.count; i++){
                            const barModelElement = barModel.get(i)
                            if (barModelElement.name === name){
                                return barModelElement
                            }
                        }
                    }

                    property var actions: {
                        "lock_unlock_edit": function(){
                            const barModelElement = barModel.getElementByName("lock_unlock_edit")
                            if (barModelElement.checked){
                                barModelElement.checked = false;
                                editField.enabled = true;
                            } else{
                                barModelElement.checked = true;
                                editField.enabled = false;
                            }
                        },
                        "save": function(){
                            TXTWindow.onSave();
                        }
                    }

                    ListElement {
                        name: "lock_unlock_edit"
                        icon: "images/lock_edit.png"
                        alter_icon: "images/unlock_edit.png"
                        action: "lock_unlock_edit"
                                toolip: "Locks edit field"
                                alter_toolip: "Unlocks edit field"
                        checked: false
                    }

                    ListElement {
                        name: "save"
                        icon: "images/save.png"
                        action: "save"
                        enabled: true
                    }
                }

                delegate: Button {
                        icon.source: model.checked ? model.alter_icon : model.icon;
//                        title: model.checked ? model.alter_tooltip : model.alter_tooltip;

                        anchors.verticalCenter: parent.verticalCenter;

                        ToolTip.visible: true;
                        ToolTip.text: "it works";

                        onHoveredChanged: {
                            console.log("it w", ToolTip.visible);
                        }

                        Text{
                            text: ""
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                        onClicked: {
                            barModel.actions[model.action]()
                        }
                    }
            }
        }

//        Rectangle {
//            color: "#B3FAA7";
//            radius: 15;
//            border.width: 1
//            border.color: "black"

//            width: 90 * root.width / 100;

//            Layout.fillHeight: true;
//            Layout.alignment: Qt.AlignCenter

//            RowLayout {
//                ListView {
//                    spacing: 8
//                    Layout.preferredWidth: 20;
//                    Layout.fillHeight: true;
//                    model: ListModel {
//                        ListElement {
//                            count: 1;
//                        }

//                        ListElement {
//                            count: 2;
//                        }
//                    }

//                    delegate:
//                        Text {
//                            text: model.count;
//                        }
//                }

        Rectangle {
            Layout.fillHeight: true;
            Layout.fillWidth: true;

           Rectangle{
               width: 95 * parent.width / 100;
               height: 90 * parent.height / 100;

                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter

                ScrollView{
                    anchors.fill: parent;
                    clip: true;

                    ScrollBar.vertical.policy: ScrollBar.AlwaysOn;
                    ScrollBar.vertical.visible: ScrollBar.vertical.size < 1;

                    ScrollBar.horizontal.policy: ScrollBar.AlwaysOn;
                    ScrollBar.horizontal.visible: ScrollBar.horizontal.size < 1;

                    TextArea {
                        id: editField;

                        Layout.fillWidth: true;
                        Layout.fillHeight: true;
                        Layout.alignment: Qt.AlignCenter;

                        enabled: true;
                        color: "black";
                        focus: true;
                        text: TXTWindow.onReadText();

                        font.pointSize: 24;
                        wrapMode: TextEdit.WrapAnywhere;
                        selectByMouse: true;

                        background: Rectangle {
                            color: "#B3FAA7";
                            radius: 10;
                            border.width: 1;
                            border.color: "black";
                        }

                        onTextChanged: {
                            console.log(editField.contentHeight, editField.lineCount)
                            TXTWindow.onWriteText(editField.text);
                            if (Storage.getAutoSave() === "true"){
                                TXTWindow.onSave();
                            }
                        }
                    }
           }
           }
        }

        Rectangle {
            id: bottomMenu;
            color: "#D9D9D9";
            Layout.fillWidth: true;
            Layout.preferredHeight: 10 * parent.height / 100;
            Layout.alignment: Qt.AlignCenter;

            ListView {
                anchors.fill: parent;
                orientation: ListView.Horizontal;
                anchors.bottom: parent.bottom
                anchors.verticalCenter: parent.verticalCenter;
                anchors.horizontalCenter: parent.horizontalCenter;
                Layout.alignment: Qt.AlignRight;
                spacing: 1;

                model: ListModel {
                    id: bottomModel

                    property var actions: {
                        "increase_font": function(){
                            editField.font.pointSize += 1;
                        },
                        "decrease_font": function(){
                            editField.font.pointSize -= 1;
                        },
                    }

                    ListElement {
                        icon: "images/decrease_font.png"
                        action: "decrease_font"
                    }

                    ListElement {
                        icon: "images/increase_font.png"
                        action: "increase_font"
                    }
                }

                delegate: Button {
                        Layout.alignment: Qt.AlignRight;
                        anchors.verticalCenter: parent.verticalCenter;
                        icon.source: model.icon;

                        Text{
                            text: ""
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        onClicked: bottomModel.actions[model.action]()
                    }
            }
        }
    }
}
