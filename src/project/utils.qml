import QtQuick 2.15

Item{
    id: utils

    function CreateWindow(fileName){
        var component = Qt.createComponent(fileName)
        var window = component.createObject(root)
        window.show()
    }
}
