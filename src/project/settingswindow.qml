import QtQuick 2.15

import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls

Item {
    id: root;
    focus: true;
    visible: true;
    height: 55 * Screen.desktopAvailableHeight / 100;
    width: 30 * Screen.desktopAvailableWidth / 100;

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
                name: "languages";
                target: "language";
            }
            ListElement {
                name: "about";
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
                Text{
                    text: model.name;
                    color: "red";
                }
                onClicked: menuModel.actions[model.target]();
            }
        }

        ListView{
            model: menuModel;
            delegate: menuDelegate;
            clip: true;
            Layout.fillHeight: true;
            Layout.preferredWidth: 30 * root.width / 100;
            Layout.alignment: Qt.AlignCenter;
        }

        Rectangle {
            id: menuBlock;
            color: "blue";
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

            TextEdit {
                id: language;
                visible: false;
                text: "language";
            }

            TextEdit {
                id: about;
                visible: false;
                text: "about";
            }
        }
    }
}
