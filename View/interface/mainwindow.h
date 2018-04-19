#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "playernumber.h"
#include "information.h"
#include "utils.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void OnControllerConnect();
    void OnControllerDisconnect();
    void SetMsgSender(MsgSender msgSender);

private slots:
    void on_playButton_clicked();

    void on_infoButton_clicked();

    void on_languageButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    PlayerNumber *window = nullptr;
    Information *rulesWindow = nullptr;
    MsgSender m_msgSender = nullptr;
};

#endif // MAINWINDOW_H
