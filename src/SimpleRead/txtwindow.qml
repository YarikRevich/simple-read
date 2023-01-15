import QtQuick 2.15

import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import Qt.labs.platform as Labs
//import "storage.js" as Storage

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
                        },

                        "information": function(){
                            console.log("Information button pressed");
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

                    ListElement {
                        name: "information"
                        icon: "images/information.png"
                        action: "information"
                        enabled: true
                    }
                }

                delegate: Button {
                        icon.source: model.checked ? model.alter_icon : model.icon;
//                        title: model.checked ? model.alter_tooltip : model.alter_tooltip;

                        anchors.verticalCenter: parent.verticalCenter;

//                        ToolTip.visible: true;
//                        ToolTip.text: "it works";

//                        onHoveredChanged: {
//                            console.log("it w", ToolTip.visible);
//                        }

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
                    id: lineScroll;
                    anchors.fill: parent;
                    clip: true;

                    ScrollBar.vertical.policy: ScrollBar.AlwaysOn;
                    ScrollBar.vertical.visible: ScrollBar.vertical.size < 1;

                    ScrollBar.horizontal.policy: ScrollBar.AlwaysOn;
                    ScrollBar.horizontal.visible: ScrollBar.horizontal.size < 1;


                    onContentHeightChanged: {
                        console.log(lineScroll.contentHeight, "CHANGED");
                    }


                    Rectangle {
                        id: lineCounter;
                        color: "#B3FAA7";
                        implicitWidth: 3 * scrollBody.width / 100;
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

                        enabled: true;
                        color: "black";
                        focus: true;
                        renderType: Text.NativeRendering;

                        font.pointSize: 24;
                        wrapMode: TextEdit.WrapAnywhere;
                        selectByMouse: true;

                        property bool loaded: false;

                        background:
                            Rectangle {
                            color: "#B3FAA7";
                            radius: 10;
                            border.width: 1;
                            border.color: "black";
                        }

                        onTextChanged: {
//                            console.log(editField.lineCount, editField.text.length, editField.width, editField.font.pointSize, editField.width / editField.font.pixelSize);
//                            TXTWindow.onWriteText(editField.text);
                            if (Storage.getAutoSave() === "true"){
//                                TXTWindow.onSave();
                            }
                        }
                        onLineCountChanged: {
                            lineCounter.reloadHeight();
                            lineCounter.reloadLines();

//                            console.log(lineScroll.contentHeight, lineScroll.height);
//                            console.log(editField.text.length, editField.y, editField.font.pixelSize, editField.contentWidth, editField.font.letterSpacing, lineScroll.contentHeight);
//                            console.log(lineScroll.height, editField.text.length, lineScroll.font.pixelSize, editField.width, lineScroll.contentHeight, editField.lineCount);
                        }

                        Component.onCompleted: {
                            editField.loaded = true;
//                            const contentSize = TXTWindow.getContentSize()
//                            console.log((contentSize - lineScroll.height) < 0);
//                            if ((contentSize - lineScroll.height) < 0){
//                                text = TXTWindow.onReadText(0, -1);
//                            }else{
//                                const shiftLineNumber = parseInt((contentSize - lineScroll.height) / editField.font.pixelSize);
//                                console.log(shiftLineNumber, contentSize, lineScroll.height, editField.font.pixelSize);
//                            }

                            text = TXTWindow.onReadText(0, -1);

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

    Labs.MessageDialog {
        id: messageDialog
        title: "Extension error"
        text: "An extension of the chosen file is not supported yet."
    }

    Binding {
        target: {
            messageDialog.open()
        }
        when: editField.loaded;
        delayed: true;
    }

    Connections {
        id: exceptionsConnection
        target: Exceptions;

        property bool loaded: false;
        function onError(msg){
            showErrorDialogWindow()
        }

        function onWarning(msg){
            showWarningDialogWindow()
        }
    }
}
