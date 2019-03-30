//https://doc-snapshots.qt.io/qt5-5.12/qml-qtquick-tableview.html#details
//https://doc.qt.io/qt-5/qtquick-modelviewsdata-cppmodels.html
//https://andrew-jones.com/blog/qml2-to-c---and-back-again-with-signals-and-slots/ !!!!!
//https://felgo.com/cross-platform-development/how-to-expose-a-qt-cpp-class-with-signals-and-slots-to-qml
//https://stackoverflow.com/questions/21270969/using-a-qabstracttablemodel-with-a-qml-tableview-only-displays-the-1st-column

import QtQuick 2.12
import QtQuick.Layouts 1.3
import QtQuick.Window 2.10
//import QtQuick.Controls 2.4
//import QtQuick.Controls 1.4 as OldControls
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

//import TableModel 1.0

ApplicationWindow {
    id: appWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("KvantProgTest")

    property int elementMargin: 5
    signal setFileName(string str)

    function setTextFieldText(str){
        fileNameTextField.text = str;
    }

    FileDialog{
        id: openFileDialog
        title: "Open file"
        folder: shortcuts.home
        selectExisting: true
        nameFilters: ["All files (*)"]
        onAccepted: {
            fileNameTextField.text = fileUrl;
            setFileName(fileNameTextField.text);
        }
        onRejected: {
            fileNameTextField.text = "Canceled";
        }
    }

    TextField {
        id :fileNameTextField
        width: (parent.width*4)/5 - openFileBtn.anchors.leftMargin - openFileBtn.anchors.rightMargin
               - anchors.leftMargin;
//        height: 30

        anchors {
            top: parent.top
            left: parent.left
            leftMargin: elementMargin
            topMargin: elementMargin
        }
        readOnly: true
        horizontalAlignment: TextInput.AlignHCenter
    }

    Button {
        id: openFileBtn
        width: parent.width/5
        height: fileNameTextField.height
        anchors {
            top: parent.top
            left: fileNameTextField.right
            topMargin: elementMargin
            leftMargin: elementMargin
            rightMargin: elementMargin
        }
        text: "Open file"
        onClicked: {
            openFileDialog.open();
        }
    }

    TableView{
        id: tableView
        visible: true
        frameVisible: true
        parent: appWindow
        implicitWidth: parent.width

        anchors {
            left: parent.left
            right: parent.right
            top: fileNameTextField.bottom
            bottom: parent.bottom
            leftMargin: elementMargin
            rightMargin: elementMargin
            topMargin: elementMargin
            bottomMargin: elementMargin
        }

        TableViewColumn {
            id: idColumn
            title: "USER_ID"
            role: "user_id"
            movable: false
            resizable: false
            width: tableView.implicitWidth/3
        }

        TableViewColumn {
            id: nameColumn
            title: "USER_NAME"
            role: "user_name"
            movable: false
            resizable: false
            width: tableView.implicitWidth/3
        }

        TableViewColumn {
            id: phoneColumn
            title: "USER_PHONE"
            role: "user_phone"
            movable: false
            resizable: false
            width: tableView.implicitWidth/3
        }

        model: TableModel
    }
}
