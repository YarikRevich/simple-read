import QtQuick 2.15
import QtQuick.Dialogs

//Item{
//    id: utils

//    function CreateWindow(fileName){
//        var component = Qt.createComponent(fileName)
//        var window = component.createObject(root)
//        window.show()
//    }
// }

MessageDialog {
    id: messageDialog
    title: "May I have your attention please"
    text: "It's so cool that you are using Qt Quick."
    visible: true;
//    onAccepted: {
//        console.log("And of course you could only agree.")
//        Qt.quit()
//    }
}
