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
            id: menu;
            Layout.fillHeight: true;
            Layout.preferredWidth: 30 * root.width / 100;
            model: ListModel {
                id: menuModel;

                function setFontSizeForAllElements(fontSize){
                    for (let i = 0; i < menuModel.count; i++){
                        menuModel.get(i).fontSize = fontSize;
                    }
                }

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
                        },
                        "default_font_size": Storage.DEFAULT_INTERFACE_FONT_SIZE,
                }
                ListElement {
                    name: QT_TR_NOOP("Languages");
                    target: "language";
                    fontSize: "default_font_size";
                }
                ListElement {
                    name: QT_TR_NOOP("About");
                    target: "about";
                    fontSize: "default_font_size";
                }
            }
            delegate: Button {
                width: 80 * menu.width / 100;

                text: qsTr(model.name);
                font.pixelSize: model.fontSize === "default_font_size" ? menuModel.actions[model.fontSize](): model.fontSize;

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

            border.width: 1;
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
                        id: languageModel

                        function setFontSizeForAllElements(fontSize){
                            for (let i = 0; i < languageModel.count; i++){
                                languageModel.get(i).fontSize = fontSize;
                            }
                        }

                        property var actions : {
                            "default_font_size": Storage.DEFAULT_INTERFACE_FONT_SIZE,
                        }

                        ListElement {
                            text: QT_TR_NOOP("English");
                            code: "en";
                            imageSource: "images/united-states.png";
                            fontSize: "default_font_size";
                        }
                        ListElement {
                            text: QT_TR_NOOP("Polish")
                            code: "pl";
                            imageSource: "images/poland.png";
                            fontSize: "default_font_size";
                        }
                        ListElement {
                            text: QT_TR_NOOP("Ukrainian");
                            code: "uk";
                            imageSource: "images/ukraine.png";
                            fontSize: "default_font_size";
                        }
                    }
                delegate: Button {


                    anchors.horizontalCenter: parent.horizontalCenter
                    text: " " + qsTr(model.text);

                    font.pixelSize: model.fontSize === "default_font_size" ? languageModel.actions[model.fontSize](): model.fontSize;

                    icon.color: "transparent";
                    icon.source: model.imageSource;
                }

                function updateDisplayText(text){
                    displayText = qsTr("Chosen language") + ": " + text;
                }

                onActivated: {
                    Storage.setCurrentLanguage(languageModel.get(currentIndex).code);
                    TranslatorRegistrator.setLanguage(languageModel.get(currentIndex).code);
                    updateDisplayText(qsTr(languageModel.get(currentIndex).text));
                }
                Component.onCompleted: {
                    const currentLanguage = Storage.getCurrentLanguage();
                    for( let i = 0; i < languageModel.rowCount(); i++ ) {
                        if (currentLanguage === languageModel.get(i).code){
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

                    function setFontSizeForAllElements(fontSize){
                        for (let i = 0; i < aboutModel.count; i++){
                            aboutModel.get(i).fontSize = fontSize;
                        }
                    }

                    property var actions : {
                        "link": ' <html><style type="text/css"></style><a href="http://google.com">GitHub</a></html>',
                        "version": ": " + Application.version,
                        "default_font_size": Storage.DEFAULT_INTERFACE_FONT_SIZE,
                    }

                    ListElement {
                        text: QT_TR_NOOP("SimpleRead is an open-source project")
                        fontSize: "default_font_size";
                    }

                    ListElement {
                        text: QT_TR_NOOP("More information can be find on");
                        interactive_text: "link";
                        link: "https://github.com/YarikRevich/simple-read";
                        fontSize: "default_font_size";
                    }

                    ListElement {
                        text: QT_TR_NOOP("Version");
                        interactive_text: "version";
                        fontSize: "default_font_size";
                    }
                }
                delegate: Text {
                    padding: 2;
                    onLinkActivated: Qt.openUrlExternally(model.link);
                    text: qsTr(model.text) + (model.interactive_text ? aboutModel.actions[model.interactive_text] : "");
                    anchors.horizontalCenter: parent.horizontalCenter;
                    font.pixelSize: model.fontSize === "default_font_size" ? aboutModel.actions[model.fontSize](): model.fontSize;
                }

                Layout.fillHeight: true;
                Layout.preferredWidth: 80 * menuBlock.width / 100;
                Layout.alignment: Qt.AlignCenter;
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
                aboutModel.setFontSizeForAllElements(interfaceFontSize);
                about.forceLayout();

                menuModel.setFontSizeForAllElements(interfaceFontSize);
                menu.forceLayout();

                languageModel.setFontSizeForAllElements(interfaceFontSize);
                language.font.pixelSize = interfaceFontSize;
            }
        }
    }
}
