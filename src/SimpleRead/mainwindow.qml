import QtQuick 2.15

import QtQuick.Controls
import QtQuick.Dialogs
import Qt.labs.platform as Labs

ApplicationWindow {
    id: root;
    title: qsTr("SimpleRead");
    visible: true;

    minimumHeight: 10 * Screen.desktopAvailableWidth / 100;
    minimumWidth: 40 * Screen.desktopAvailableWidth / 100;
    maximumHeight: 10 * Screen.desktopAvailableWidth / 100;
    maximumWidth: 40 * Screen.desktopAvailableWidth / 100;

    color: Qt.rgba(Math.random(),Math.random(),Math.random(),1);

    Labs.MenuBar {
        id: menuBar
        Labs.Menu {
              id: fileMenu
              title: qsTr("File")
              Labs.MenuItem {
                  text: qsTr("&Open")
                  onTriggered: {}
              }
              Labs.MenuItem {
                  text: qsTr("&Save")
                  onTriggered: {}
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
                  onTriggered: {}
              }
              Labs.MenuItem {
                  text: qsTr("&Zoom Out")
                  onTriggered: {}
              }
        }

        Labs.Menu {
               id: helpMenu
               title: qsTr("Help")
               Labs.MenuItem {
                   text: qsTr("&About")
                   onTriggered: {}
               }
         }
    }

    Row{
        anchors.verticalCenter: parent.verticalCenter;
        anchors.horizontalCenter: parent.horizontalCenter;
        Button{
            text: qsTr("Open file");
            onClicked: fileDialogWindow.open();
        }
        Button {
            text: qsTr("Settings");
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
                   DOCXWindow.onOpen();
                   DOCXWindow.setFileName(cleanFilePath(docxFileMatch[0]));
                   DOCXWindow.exec();
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
                   messageDialog.open();

                   // TXTWindow.onOpen();
                   // TXTWindow.setFileName(cleanFilePath(txtFileMatch[0]));
                   // TXTWindow.exec();
                   return
            };

            const csvFileMatch = selectedFile.match(fileDialogWindow.csvFileMatch);
            if (csvFileMatch){
                   messageDialog.open();

                   // TODO: Fix csv file parser
                   // CSVWindow.onOpen();
                   // CSVWindow.setFileName(cleanFilePath(csvFileMatch[0]));
                   // CSVWindow.exec();
                   return
            };
        }
    }
}
