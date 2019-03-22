//https://doc-snapshots.qt.io/qt5-5.12/qml-qtquick-tableview.html#details
//https://doc.qt.io/qt-5/qtquick-modelviewsdata-cppmodels.html
//https://andrew-jones.com/blog/qml2-to-c---and-back-again-with-signals-and-slots/ !!!!!
//https://felgo.com/cross-platform-development/how-to-expose-a-qt-cpp-class-with-signals-and-slots-to-qml

import QtQuick 2.10
import QtQuick.Layouts 1.3
import QtQuick.Window 2.10
import QtQuick.Controls 2.4
import QtQuick.Controls 1.4 as OldControls
import QtQuick.Dialogs 1.2

//import TableModel 1.0

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

//    function setTableViewVisible(tableViewModel){
//        tableView.visible = true;
//        tableView.model = tableViewModel;
//    }

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
//        visible: false
//        frameVisible: true
//        sortIndicatorVisible: true
//        property int tableViewWidth: parent.width - 2*elementMargin
//        anchors.topMargin: 13
//        clip: false

//        anchors {
//            left: parent.left
//            right: parent.right
//            top: fileNameTextField.bottom
//            bottom: parent.bottom
//            leftMargin: elementMargin
//            rightMargin: elementMargin
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
