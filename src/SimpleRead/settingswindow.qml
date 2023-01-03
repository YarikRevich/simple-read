import QtQuick 2.15

import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import "storage.js" as Storage

Item {
    id: root;
    focus: true;
    visible: true;
    height: 40 * Screen.desktopAvailableHeight / 100;
    width: 40 * Screen.desktopAvailableWidth / 100;

    RowLayout {
        id: layout;
        anchors.fill: parent;
        anchors.centerIn: parent;
        anchors.margins: 2;
        spacing: 1;

        ListModel {
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
                name: qsTr("Languages");
                target: "language";
            }
            ListElement {
                name: qsTr("About");
                target: "about";
            }
        }

        /*!
          \brief Delegate component, which helps to manage menu
          \qmltype Component
        */
        Component {
            id: menuDelegate;

            Button {
                text: model.name;
                width: 80 * menuList.width / 100;

                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: menuModel.actions[model.target]();
            }
        }

        ListView{
            id: menuList;
            Layout.fillHeight: true;
            Layout.preferredWidth: 30 * root.width / 100;
            model: menuModel;
            delegate: menuDelegate;
            Layout.alignment: Qt.AlignCenter;
        }

        Rectangle {
            id: menuBlock;

            Layout.fillWidth: true;
            Layout.fillHeight: true;
            Layout.alignment: Qt.AlignCenter

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
                            text: qsTr("English");
                            code: "en";
                            imageSource: "images/united-states.png";
                        }
                        ListElement {
                            text: qsTr("Polish")
                            code: "pl";
                            imageSource: "images/poland.png";
                        }
                        ListElement {
                            text: qsTr("Ukrainian");
                            code: "uk";
                            imageSource: "images/ukraine.png";
                        }
                    }
                delegate: languageDelegate;
                onCurrentIndexChanged: {
                    displayText = "Chosen language: " + model.get(currentIndex).text;

                }
                onActivated: {
                    Storage.setCurrentLanguage(model.get(currentIndex).code);
                    TranslatorRegistrator.setLanguage(model.get(currentIndex).code);
                }
                Component.onCompleted: {
                    const currentLanguage = Storage.getCurrentLanguage();
                    for( var i = 0; i < model.rowCount(); i++ ) {
                        if (currentLanguage === model.get(i).code){
                            language.currentIndex = i;
                            break;
                        }
                    }
                }
            }

            Component {
                id: languageDelegate;
                Button {
                    text: " " + model.text;

                    anchors.horizontalCenter: parent.horizontalCenter

                    icon.color: "transparent";
                    icon.source: model.imageSource;
                }

            }

            Rectangle {
                id: about;
                visible: false;
//                width: 80 * menuBlock.width / 100;

                Component {
                    id: aboutDelegate;

                    Text {
                        text: aboutModel.actions[model.key];
                        width: 100;
                        anchors.horizontalCenter: parent.horizontalCenter;
                    }
                }

                ListView{
                    anchors.horizontalCenter: parent.horizontalCenter;

                    model: ListModel {
                        id: aboutModel;

                        property var actions : {
                            "description": "SimpleRead is an open-source project",
                            "version": "Version: " + Application.version,
                        }

                        ListElement {
                            key: "description";
                        }
                        ListElement {
                            key: "version";
                        }
                    }
                    delegate: aboutDelegate;

                    Layout.fillHeight: true;
                    Layout.preferredWidth: 80 * menuBlock.width / 100;
                    Layout.alignment: Qt.AlignCenter;
                }

            }
        }
    }
}
