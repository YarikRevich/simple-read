import QtQuick 2.15

import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import "storage.js" as Storage

Rectangle {
    id: root;
    focus: true;
    visible: true;
    height: 40 * Screen.desktopAvailableHeight / 100;
    width: 40 * Screen.desktopAvailableWidth / 100;
    color: "#B3FAA7";

    RowLayout {
        id: layout;
        anchors.fill: parent;
        anchors.centerIn: parent;
        anchors.margins: 2;
        spacing: 1;

        ListView{
            id: menuList;
            Layout.fillHeight: true;
            Layout.preferredWidth: 30 * root.width / 100;
            model: ListModel {
                id: menuModel;

                /*!
                  \brief Contains callbacks, which help to open certain menu blocks
                  \qmltype map
                */
                property var actions : {
                        "language": function(){
                           menuBlock.hideAllMenues();
                           language.visible = true;
                        },
                        "about": function(){
                            menuBlock.hideAllMenues();
                            about.visible = true;
                        }
                }
                ListElement {
                    name: QT_TR_NOOP("Languages");
                    target: "language";
                }
                ListElement {
                    name: QT_TR_NOOP("About");
                    target: "about";
                }
            }
            delegate: Button {
                text: qsTr(model.name);
                width: 80 * menuList.width / 100;

                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: menuModel.actions[model.target]();
            }
            Layout.alignment: Qt.AlignCenter;
        }

        Rectangle {
            id: menuBlock;

            Layout.fillWidth: true;
            Layout.fillHeight: true;
            Layout.alignment: Qt.AlignCenter

            radius: 10;

            /*!
              \brief Hides all the menues blocks opened with a help of menu
              \qmltype function
            */
            function hideAllMenues() {
                language.visible = false;
                about.visible = false;
            }

            /*!
              \brief Dropdown menu, which is used for interface language selection
            */
            ComboBox {
                id: language;
                width: 80 * menuBlock.width / 100;

                anchors.horizontalCenter: parent.horizontalCenter;

                model: ListModel {
                        id: model
                        ListElement {
                            text: QT_TR_NOOP("English");
                            code: "en";
                            imageSource: "images/united-states.png";
                        }
                        ListElement {
                            text: QT_TR_NOOP("Polish")
                            code: "pl";
                            imageSource: "images/poland.png";
                        }
                        ListElement {
                            text: QT_TR_NOOP("Ukrainian");
                            code: "uk";
                            imageSource: "images/ukraine.png";
                        }
                    }
                delegate: Button {
                    text: " " + qsTr(model.text);

                    anchors.horizontalCenter: parent.horizontalCenter

                    icon.color: "transparent";
                    icon.source: model.imageSource;
                }

                function updateDisplayText(text){
                    displayText = qsTr("Chosen language") + ": " + text;
                }

                onActivated: {
                    Storage.setCurrentLanguage(model.get(currentIndex).code);
                    TranslatorRegistrator.setLanguage(model.get(currentIndex).code);
                    updateDisplayText(qsTr(model.get(currentIndex).text));
                }
                Component.onCompleted: {
                    const currentLanguage = Storage.getCurrentLanguage();
                    for( var i = 0; i < model.rowCount(); i++ ) {
                        if (currentLanguage === model.get(i).code){
                            language.currentIndex = i;
                            break;
                        }
                    }
                    updateDisplayText(qsTr(model.get(language.currentIndex).text));
                }
            }

            ListView{
                id: about;
                visible: false;
                anchors.fill: parent;
                anchors.horizontalCenter: parent.horizontalCenter;

                model: ListModel {
                    id: aboutModel;

                    property var actions : {
                        "description": QT_TR_NOOP("SimpleRead is an open-source project"),
                        "link": QT_TR_NOOP("More information can be find on") + ' <html><style type="text/css"></style><a href="http://google.com">GitHub</a></html>',
                        "version": QT_TR_NOOP("Version") + ": " + Application.version,
                    }

                    ListElement {
                        key: "description";
                        link: "";
                    }

                    ListElement {
                        key: "link";
                        link: "https://github.com/YarikRevich/simple-read";
                    }

                    ListElement {
                        key: "version";
                        link: "";
                    }
                }
                delegate: Text {
                    padding: 2;
                    onLinkActivated: Qt.openUrlExternally(model.link);
                    text: qsTr(aboutModel.actions[model.key]);
                    anchors.horizontalCenter: parent.horizontalCenter;
                }

                Layout.fillHeight: true;
                Layout.preferredWidth: 80 * menuBlock.width / 100;
                Layout.alignment: Qt.AlignCenter;
            }
        }
    }
}
