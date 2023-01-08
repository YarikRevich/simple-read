import QtQuick 2.15

import QtQuick.Controls
import QtQuick.Dialogs
import Qt.labs.platform as Labs
import "storage.js" as Storage

ApplicationWindow {
    id: root;
    title: qsTr("SimpleRead");
    visible: true;

    minimumHeight: 10 * Screen.desktopAvailableWidth / 100;
    minimumWidth: 40 * Screen.desktopAvailableWidth / 100;
    maximumHeight: 10 * Screen.desktopAvailableWidth / 100;
    maximumWidth: 40 * Screen.desktopAvailableWidth / 100;

    color: "#B3FAA7";

    property var currentFileWindow;

    Labs.MenuBar {
        id: menuBar
        Labs.Menu {
              id: fileMenu
              title: qsTr("File")
              Labs.MenuItem {
                  text: qsTr("&Open")
                  onTriggered: fileDialogWindow.open();
              }
              Labs.MenuItem {
                  text: qsTr("&Save")
                  onTriggered: currentFileWindow.onSave();
              }
              Labs.MenuItem {
                  text: qsTr("&Auto save")
                  checkable: true
                  checked: Storage.getAutoSave() === "true" ? true : false
                  onCheckedChanged: checked ? Storage.setAutoSave("true") : Storage.setAutoSave("false")
              }
              Labs.MenuSeparator{}
              Labs.MenuItem {
                  text: qsTr("&Print")
                  onTriggered: {}
              }
        }

        Labs.Menu {
              id: viewMenu
              title: qsTr("&View")
              Labs.MenuItem {
                  text: qsTr("&Zoom In")
                  onTriggered: {
                      Storage.setInterfaceFontSize(Storage.getInterfaceFontSize() + 1);
                  }
              }
              Labs.MenuItem {
                  text: qsTr("&Zoom Out")
                  onTriggered: {
                      Storage.setInterfaceFontSize(Storage.getInterfaceFontSize() - 1);
                  }
              }
        }

        Labs.Menu {
               id: helpMenu
               title: qsTr("Help")
               Labs.MenuItem {
                   text: qsTr("&About")
                   onTriggered: {
                        SettingsWindow.onOpen();
                   }
               }
         }
    }

    Row{
        anchors.verticalCenter: parent.verticalCenter;
        anchors.horizontalCenter: parent.horizontalCenter;
        Button{
            contentItem: Text {
                id: openFileButtonContent;
                text: qsTr("Open file");
                font.pointSize: Storage.DEFAULT_INTERFACE_FONT_SIZE;
            }

            onClicked: fileDialogWindow.open();
        }
        Button {
            contentItem: Text {
                id: settingsButtonContent;
                text: qsTr("Settings");
                font.pointSize: Storage.DEFAULT_INTERFACE_FONT_SIZE;
            }

            onClicked: SettingsWindow.onOpen();
        }
    }

    Labs.MessageDialog {
        id: messageDialog
        title: "Extension error"
        text: "An extension of the chosen file is not supported yet."
    }

    /*!
      \brief
      \qmltype FileDialog
    */
    FileDialog {
        id: fileDialogWindow;
        title: qsTr("Please choose a file");

        readonly property string fileFilter: "Files (*.docx *.csv *.pdf *.txt)";

        readonly property string docxFileMatch: "^(.+)\\/([^\\/]+)\\.docx$";
        readonly property string pdfFileMatch: "^(.+)\\/([^\\/]+)\\.pdf$";
        readonly property string txtFileMatch: "^(.+)\\/([^\\/]+)\\.txt$";
        readonly property string csvFileMatch: "^(.+)\\/([^\\/]+)\\.csv$";

        nameFilters: [fileDialogWindow.fileFilter];
        onAccepted: {
            function cleanFilePath(filePath){
                return filePath.replace("file://", "")
            }

            const selectedFile = fileDialogWindow.selectedFiles.toString();

            const docxFileMatch = selectedFile.match(fileDialogWindow.docxFileMatch);
            if (docxFileMatch){
                    currentFileWindow = DOCXWindow;

                    DOCXWindow.setFileName(cleanFilePath(docxFileMatch[0]));
                    DOCXWindow.onInit();
                    DOCXWindow.onOpen();
                    return
            };

            const pdfFileMatch = selectedFile.match(fileDialogWindow.pdfFileMatch);
            if (pdfFileMatch){
                   messageDialog.open();

                   // PDFWindow.onOpen();
                   // PDFWindow.setFileName(cleanFilePath(pdfFileMatch[0]));
                   // PDFWindow.exec();
                   return
            };

            const txtFileMatch = selectedFile.match(fileDialogWindow.txtFileMatch);
            if (txtFileMatch){
                    currentFileWindow = TXTWindow;

                    TXTWindow.setFileName(cleanFilePath(txtFileMatch[0]));
                    TXTWindow.onInit();
                    TXTWindow.onOpen();
                    return
            };

            const csvFileMatch = selectedFile.match(fileDialogWindow.csvFileMatch);
            if (csvFileMatch){
                    currentFileWindow = CSVWindow;

                    CSVWindow.setFileName(cleanFilePath(csvFileMatch[0]));
                    CSVWindow.onInit();
                    CSVWindow.onOpen();
                   return
            };
        }
    }

    Timer {
        interval: 100;
        running: true;
        repeat: true;
        onTriggered: {
            if (Storage.isInterfaceFontSizeChanged()){
                const interfaceFontSize = String(Storage.getInterfaceFontSize());
                openFileButtonContent.font.pointSize = interfaceFontSize;
                settingsButtonContent.font.pointSize = interfaceFontSize;
            }
        }
    }

    Binding {
            target: {
                TranslatorRegistrator.setLanguage(Storage.getCurrentLanguage());
            }
            when: TranslatorRegistrator;
            delayed: true;
    }
}
