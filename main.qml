import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    visible: true
    width: 800
    height: 600
    title: "Qt Adjuster — Web"
    color: "#f4f4f4"

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        Text {
            text: "Настройка параметров"
            font.pixelSize: 22
            font.bold: true
            Layout.alignment: Qt.AlignHCenter
        }

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            model: parameterModel
            spacing: 2

            header: Rectangle {
                width: listView.width
                height: 40
                color: "#e0e0e0"
                z: 2
                RowLayout {
                    anchors.fill: parent
                    anchors.leftMargin: 15; anchors.rightMargin: 15
                    Text { text: "Параметр"; font.bold: true; Layout.fillWidth: true }
                    Text { text: "Значение"; font.bold: true; Layout.preferredWidth: 100; horizontalAlignment: Text.AlignHCenter }
                    Text { text: "Ед. изм."; font.bold: true; Layout.preferredWidth: 80 }
                }
            }

            delegate: Rectangle {
                width: listView.width
                height: 50
                color: "white"
                radius: 4

                RowLayout {
                    anchors.fill: parent
                    anchors.leftMargin: 15; anchors.rightMargin: 15

                    Text {
                        text: p_name
                        Layout.fillWidth: true
                        font.pixelSize: 16
                    }

                    TextField {
                        text: p_value
                        Layout.preferredWidth: 100
                        horizontalAlignment: Text.AlignHCenter
                        selectByMouse: true
                        onEditingFinished: {
                            console.log("Новое значение для " + p_name + ": " + text)
                        }
                    }

                    Text {
                        text: p_unit
                        Layout.preferredWidth: 80
                        color: "#666"
                        font.pixelSize: 14
                    }
                }
            }
        }
    }
}
