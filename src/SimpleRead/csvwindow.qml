import QtQuick 2.15

import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import Qt.labs.qmlmodels
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
                            CSVWindow.onSave();
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
                            if (lineCounterModel.count > tableModel.rowCount){
                                for (var a = lineCounterModel.count; a >= tableModel.rowCount; a--){
                                    lineCounterModel.remove(a);
                                }
                            }else{
                                for (let a = lineCounterModel.count; a < tableModel.rowCount; a++){
                                    lineCounterModel.set(a, {count: a+1});
                                }
                            }
                        }

                        ListView {
                            id: lineCounterList;
                            anchors.fill: parent;
                            anchors.topMargin: 5;
                            anchors.horizontalCenter: parent.horizontalCenter;

                            function setFontSizeByIncreament(increament){
                                lineCounterList.actions["fontSize"] += increament;
                            }

                            property var actions : {
                                "fontSize": Storage.DEFAULT_INTERFACE_FONT_SIZE,
                            }

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
                                    font.pixelSize: lineCounterList.actions["fontSize"];
                            }
                        }
                    }


                    TableView {
                        id: editField;
                        anchors.fill: parent
                        columnSpacing: 1
                        rowSpacing: 1
                        clip: true

                        function setFontSizeByIncreament(increament){
                            editField.actions["fontSize"] += increament;
                        }

                        property var actions : {
                            "fontSize": Storage.DEFAULT_INTERFACE_FONT_SIZE,
                        }

                        property bool loaded: false;

                        columnWidthProvider: function(column) {
                            return editField.actions["fontSize"] * 10;
                        };

                        rowHeightProvider: function(row){
                            return editField.actions["fontSize"] * 7;
                        }

                        model: TableModel {
                            id: tableModel;

                            TableModelColumn {
                                display: "stub"
                            }


//                            Tab {
//                                display: "name"
//                            }

//                            TableModelColumn {
//                                display: "color"
//                            }
                        }

                        delegate: Rectangle {
                            color: "#B3FAA7";
                            border.width: 1

                            TextEdit {
                                text: display
                                clip: true;
                                font.pixelSize: editField.actions["fontSize"];
                                wrapMode: TextEdit.WrapAnywhere;
                                anchors.centerIn: parent
                                onTextChanged: {
                                    if (editField.loaded){
//                                        const ix = tableModel.index(0, 0);
//                                        tableModel.setData(ix, "display", "Yaroslav")
                                    }
                                }
                            }
                        }

                        Component.onCompleted: {
                            editField.loaded = true;
                            tableModel.removeColumn("stub");
                            tableModel.insertColumn({"display": "Name"});
//                            tableModel.setData("Name", "display", "it works");
//                            tableModel.appendRow({"Name": "it works"})

//                            const data = CSVWindow.onReadTable();
//                            for (let column in data){


//                                const row = data[column];
//                                for (let i = 0; i < row.length; i++){
//                                    tableModel.appendRow({Name: row[i]})
//                                }
//                            }


//                            tableModel.insertColumn("Yaroslav")
//                            tableModel.appendRow({
//                                                     "name": "Yaroslav",
//                                                     "color": "Jjjk",
//                                                 })
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
                            lineCounterList.setFontSizeByIncreament(-1)
                            lineCounterList.forceLayout()

                            editField.setFontSizeByIncreament(1)
                            editField.forceLayout()
//                            editField.font.pixelSize += 1;
                            editField.anchors.leftMargin += 0.08;
                            lineCounter.implicitWidth += 0.2;
                        },
                        "decrease_font": function(){
                            lineCounterList.setFontSizeByIncreament(-1)
                            lineCounterList.forceLayout()

                            editField.setFontSizeByIncreament(-1)
                            editField.forceLayout()
//                            editField.font.pixelSize -= 1;
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
