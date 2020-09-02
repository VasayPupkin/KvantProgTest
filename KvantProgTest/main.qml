import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4 as OldControls

ApplicationWindow {
    id: appWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("KvantProgTest")

    signal setFileName(string str)
    function setTextFieldText(str) {
        fileNameTextField.text = str;
    }

    FileDialog {
        id: openFileDialog
        title: "Open file"
        folder: shortcuts.home
        selectExisting: true
        nameFilters: ["CSV files (*.csv)", "All files (*)"]
        onAccepted: {
            fileNameTextField.text = fileUrl;
            setFileName(fileNameTextField.text);

        }
        onRejected: {
            fileNameTextField.text = "Canceled";
        }
    }

    Button {
        id: openFileBtn
        x: 530
        text: qsTr("Open file")
        clip: false
        highlighted: true
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 11
        onClicked: {
            openFileDialog.open();
        }
    }

    TextField {
        id: fileNameTextField
        height: 40
        horizontalAlignment: Text.AlignHCenter
        anchors.right: openFileBtn.left
        anchors.rightMargin: 11
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 11
        readOnly: true
    }

    OldControls.TableView {
        id: tableView
        clip: true
        parent: appWindow
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.top: fileNameTextField.bottom
        anchors.topMargin: 10
        frameVisible: true

        OldControls.TableViewColumn {
            id: idColumn
            title: "USER_ID"
            role: "user_id"
            movable: false
            resizable: true
            width: tableView.viewport.width/3
        }

        OldControls.TableViewColumn {
            id: nameColumn
            title: "USER_NAME"
            role: "user_name"
            movable: false
            resizable: true
            width: tableView.viewport.width/3
        }

        OldControls.TableViewColumn {
            id: phoneColumn
            title: "USER_PHONE"
            role: "user_phone"
            movable: false
            resizable: true
            width: tableView.viewport.width/3
        }

        model: TableModel
    }
}

