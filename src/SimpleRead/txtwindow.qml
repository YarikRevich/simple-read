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
                            StatisticsWindow.setStatistics(TXTWindow.getStatistics());
                            StatisticsWindow.onInit();
                            StatisticsWindow.onOpen();
                        }
                    }

                    ListElement {
                        name: "lock_unlock_edit"
                        icon: "images/lock_edit.png"
                        alter_icon: "images/unlock_edit.png"
                        action: "lock_unlock_edit"
                        tooltip: QT_TR_NOOP("Locks edit field")
                        alter_tooltip: QT_TR_NOOP("Unlocks edit field")
                        tooltip_visible: false
                        hovered: false;
                        checked: false
                    }

                    ListElement {
                        name: "save"
                        icon: "images/save.png"
                        action: "save"
                        tooltip: QT_TR_NOOP("Saves the file")
                        tooltip_visible: false
                        hovered: false;
                        enabled: true

                    }

                    ListElement {
                        name: "information"
                        icon: "images/information.png"
                        action: "information"
                        tooltip: QT_TR_NOOP("Shows detailed information about the file")
                        tooltip_visible: false
                        hovered: false;
                        enabled: true
                    }
                }

                delegate: Button {
                        Text{
                            text: ""
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                        }

                        icon.source: model.checked ? model.alter_icon : model.icon;
                        anchors.verticalCenter: parent.verticalCenter;

                        ToolTip {
                            text: qsTr(model.alter_tooltip ? (model.checked ? model.alter_tooltip : model.tooltip) : model.tooltip)
                            visible: model.tooltip_visible
                        }

                        onClicked: {
                            barModel.actions[model.action]()
                        }

                        onHoveredChanged: {
                            if (!barModel.getElementByName(model.name).hovered){
                                toolTipTimerTopBar.start();
                                barModel.getElementByName(model.name).hovered = true;
                            }else{
                                toolTipTimerTopBar.stop();
                                barModel.getElementByName(model.name).tooltip_visible = false;
                                barModel.getElementByName(model.name).hovered = false;
                            }

                        }

                        Timer {
                            id: toolTipTimerTopBar
                            interval: 2000
                            running: false
                            repeat: false
                            onTriggered: {
                                barModel.getElementByName(model.name).tooltip_visible = true;
                            }
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
                            TXTWindow.onWriteText(editField.text, 0, -1);
                            if (Storage.getAutoSave() === "true"){
                                TXTWindow.onSave();
                            }
                        }
                        onLineCountChanged: {
                            lineCounter.reloadHeight();
                            lineCounter.reloadLines();
                        }

                        Component.onCompleted: {
                            editField.loaded = true;
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

                    function getElementByName(name){
                        for (let i = 0; i < bottomModel.count; i++){
                            const bottomModelElement = bottomModel.get(i)
                            if (bottomModelElement.name === name){
                                return bottomModelElement
                            }
                        }
                    }

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
                        name: "decrease_font"
                        icon: "images/decrease_font.png"
                        action: "decrease_font"
                        tooltip: QT_TR_NOOP("Decreases font of the viewport")
                        tooltip_visible: false
                        hovered: false;
                    }

                    ListElement {
                        name: "increase_font"
                        icon: "images/increase_font.png"
                        action: "increase_font"
                        tooltip: QT_TR_NOOP("Increases font of the viewport")
                        tooltip_visible: false
                        hovered: false;
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

                        ToolTip {
                            text: qsTr(model.tooltip);
                            visible: model.tooltip_visible
                        }

                        onClicked: bottomModel.actions[model.action]()

                        onHoveredChanged: {
                            if (!bottomModel.getElementByName(model.name).hovered){
                                toolTipTimerBottomBar.start();
                                bottomModel.getElementByName(model.name).hovered = true;
                            }else{
                                toolTipTimerBottomBar.stop();
                                bottomModel.getElementByName(model.name).tooltip_visible = false;
                                bottomModel.getElementByName(model.name).hovered = false;
                            }
                        }

                        Timer {
                            id: toolTipTimerBottomBar
                            interval: 2000
                            running: false
                            repeat: false
                            onTriggered: {
                                bottomModel.getElementByName(model.name).tooltip_visible = true;
                            }
                        }
                    }
            }
        }
    }

    Labs.MessageDialog {
        id: errorDialogWindow
        title: "Error";
    }

    function showErrorDialogWindow(msg){
        errorDialogWindow.text = msg;
        errorDialogWindow.open()
    }

    Labs.MessageDialog {
        id: warningDialogWindow
        title: "Warning";
    }

    function showWarningDialogWindow(msg){
        warningDialogWindow.text = msg;
        warningDialogWindow.open()
    }

    Connections {
        id: exceptionsConnection
        target: Exceptions;

        property bool loaded: false;
        function onError(msg){
            showErrorDialogWindow(msg)
        }

        function onWarning(msg){
            showWarningDialogWindow(msg)
        }
    }
}
