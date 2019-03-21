import QtQuick 2.11
import QtQuick.Window 2.10
import QtQuick.Controls 2.4
import QtQuick.Controls 1.4 as OldControls
import QtQuick.Dialogs 1.2

import TableModel 1.0

Window {
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
        height: 30

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

//    OldControls.TableView {
//        id : tableView
////        visible: true
//        frameVisible: false
//        sortIndicatorVisible: true
//        property int tableViewWidth: parent.width - 2*elementMargin
//        clip: true

//        anchors {
//            left: parent.left
//            right: parent.right
//            top: fileNameTextField.bottom
//            bottom: parent.bottom
//            leftMargin: elementMargin
//            rightMargin: elementMargin
//            topMargin: elementMargin
//            bottomMargin: elementMargin
//        }

//        model: TableModel {}
//        itemDelegate: Rectangle {
//            implicitWidth: 50
//            implicitHeight: 50
//            Text {
//                text: display
//            }
//        }
//    }

}
