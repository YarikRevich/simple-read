import QtQuick 2.15

import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import Qt.labs.platform as Labs
import "storage.js" as Storage

Item {
    id: root;
    visible: true;
    height: 80 * Screen.desktopAvailableHeight / 100;
    width: 80 * Screen.desktopAvailableWidth / 100;

    Labs.MessageDialog {
        id: unlockEditError
        title: "Function error"
        text: "DOCX files are available only for reading"
    }

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
                            unlockEditError.open();
                        },
                    }

                    ListElement {
                        name: "lock_unlock_edit"
                        icon: "images/lock_edit.png"
                        alter_icon: "images/unlock_edit.png"
                        action: "lock_unlock_edit"
                        checked: false
                    }
                }

                delegate: Button {
                        icon.source: model.checked ? model.alter_icon : model.icon;

                        anchors.verticalCenter: parent.verticalCenter;

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

        Rectangle {
            Layout.fillHeight: true;
            Layout.fillWidth: true;

           Rectangle{
               id: scrollBody;
               width: 95 * parent.width / 100;
               height: 90 * parent.height / 100;

                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter

                    ScrollView{
                        anchors.fill: parent;
                        focus: true;
                        clip: true;

                        ScrollBar.vertical.policy: ScrollBar.AlwaysOn;
                        ScrollBar.vertical.visible: ScrollBar.vertical.size < 1;

                        ScrollBar.horizontal.policy: ScrollBar.AlwaysOn;
                        ScrollBar.horizontal.visible: ScrollBar.horizontal.size < 1;

                        Rectangle {
                            id: lineCounter;
                            implicitWidth: 3 * scrollBody.width / 100;
                            color: "#B3FAA7";
                            border.width: 1;

                            function reloadHeight(){
                                if (editField.height > scrollBody.height){
                                    lineCounter.height = editField.height;
                                }else{
                                    lineCounter.height = scrollBody.height
                                }
                            }

                            function reloadLines(){
                                if (lineCounterModel.count > editField.lineCount){
                                    for (var a = lineCounterModel.count; a >= editField.lineCount; a--){
                                        lineCounterModel.remove(a);
                                    }
                                }else{
                                    for (let a = lineCounterModel.count; a < editField.lineCount; a++){
                                        lineCounterModel.set(a, {count: a+1});
                                    }
                                }
                            }

                            ListView {
                                id: lineCounterList;
                                anchors.fill: parent;
                                anchors.topMargin: 5;
                                anchors.horizontalCenter: parent.horizontalCenter;

                                model: ListModel {
                                    id: lineCounterModel;

                                    ListElement {
                                        count: 1;
                                    }
                                }

                                delegate: Text {
                                        anchors.horizontalCenter: parent.horizontalCenter
                                        text: model.count;
                                        color: "gray";
                                        font.pixelSize: editField.font.pixelSize;
                                }
                            }
                        }

                        TextArea {
                            id: editField;
                            anchors.fill: parent;
                            anchors.leftMargin: 3 * scrollBody.width / 100;
                            Layout.alignment: Qt.AlignCenter;

                            enabled: false;
                            color: "black";
                            focus: true;
                            text: DOCXWindow.onReadText();

                            font.pointSize: 24;
                            wrapMode: TextEdit.WrapAnywhere;
                            selectByMouse: true;

                            background:
                                Rectangle {
                                color: "#B3FAA7";
                                radius: 10;
                                border.width: 1;
                                border.color: "black";
                            }

                            onTextChanged: {
                                DOCXWindow.onWriteText(editField.text);
                                if (Storage.getAutoSave() === "true"){
                                    DOCXWindow.onSave();
                                }
                            }
                            onLineCountChanged: {
                                lineCounter.reloadHeight();
                                lineCounter.reloadLines();
                            }

                            Component.onCompleted: {
                                lineCounter.reloadHeight();
                                lineCounter.reloadLines();
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
                            editField.font.pixelSize += 1;
                            editField.anchors.leftMargin += 0.08;
                            lineCounter.implicitWidth += 0.2;
                        },
                        "decrease_font": function(){
                            editField.font.pixelSize -= 1;
                            editField.anchors.leftMargin -= 0.08;
                            lineCounter.implicitWidth -= 0.2;
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
