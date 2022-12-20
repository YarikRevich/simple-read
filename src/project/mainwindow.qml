import QtQuick 2.15

import QtQuick.Controls
import QtQuick.Dialogs
import Qt.labs.platform as Labs

ApplicationWindow {
    id: root;
    title: qsTr("Project");
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
            let selectedFile = fileDialogWindow.selectedFiles.toString();

            let docxFileMatch = selectedFile.match(fileDialogWindow.docxFileMatch);
            if (docxFileMatch){
                   DOCXWindow.onOpen();
                   DOCXWindow.setFileName(docxFileMatch[0]);
                   DOCXWindow.exec();
                   return
            };

            let pdfFileMatch = selectedFile.match(fileDialogWindow.pdfFileMatch);
            if (pdfFileMatch){
                   PDFWindow.onOpen();
                   PDFWindow.setFileName(pdfFileMatch[0]);
                   PDFWindow.exec();
                   return
            };

            let txtFileMatch = selectedFile.match(fileDialogWindow.txtFileMatch);
            if (txtFileMatch){
                   TXTWindow.onOpen();
                   TXTWindow.setFileName(txtFileMatch[0]);
                   TXTWindow.exec();
                   return
            };

            let csvFileMatch = selectedFile.match(fileDialogWindow.csvFileMatch);
            if (csvFileMatch){
                   CSVWindow.onOpen();
                   CSVWindow.setFileName(csvFileMatch[0]);
                   CSVWindow.exec();
                   return
            };
        }
    }
}
