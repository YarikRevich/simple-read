import QtQuick 2.15
import QtQuick.Layouts
import "storage.js" as Storage

Rectangle {
    id: root;
    implicitHeight: 40 * Screen.desktopAvailableHeight / 100;
    implicitWidth: 40 * Screen.desktopAvailableWidth / 100;

    ColumnLayout {
        anchors.fill: parent;

        Rectangle {
            Layout.alignment: Qt.AlignCenter

            Layout.minimumHeight: 80 * root.height / 100;
            Layout.minimumWidth: 80 * root.width / 100;

            Layout.maximumHeight: 80 * root.height / 100;
            Layout.maximumWidth: 80 * root.width / 100;

            color: "#B3FAA7";
            border.width: 1;

            ListView {
                id: listView;
                anchors.fill: parent;

                model: ListModel {
                    id: listModel

                    function setFontSizeForAllElements(fontSize){
                        for (let i = 0; i < listModel.count; i++){
                            listModel.get(i).fontSize = fontSize;
                        }
                    }

                    property var actions: {
                        "loadTime": function(){
                            return StatisticsWindow.getLoadTime()
                        },

                        "fileSize": function(){
                            console.log(StatisticsWindow.getFileSize())
                            return StatisticsWindow.getFileSize()
                        },

                        "default_font_size": Storage.DEFAULT_INTERFACE_FONT_SIZE,
                    }

                    ListElement {
                        text: QT_TR_NOOP("Load time")
                        action: "loadTime"
                        fontSize: "default_font_size"
                    }

                    ListElement {
                        text: QT_TR_NOOP("File size")
                        action: "fileSize"
                        fontSize: "default_font_size"
                    }
                }

                delegate: Text {
                    padding: 5;
                    font.bold: true;
                    font.pixelSize: model.fontSize === "default_font_size" ? listModel.actions[model.fontSize]: model.fontSize;
                    text: qsTr(model.text) + ": " + listModel.actions[model.action]()
                }
            }
        }
    }

    Timer {
        interval: 100;
        running: true;
        repeat: true;
        onTriggered: {
            if (Storage.isInterfaceFontSizeChanged()){
                const interfaceFontSize = String(Storage.getInterfaceFontSize());

                listModel.setFontSizeForAllElements(interfaceFontSize);
                listView.forceLayout();
            }
        }
    }
}
