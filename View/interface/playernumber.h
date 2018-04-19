#ifndef PLAYERNUMBER_H
#define PLAYERNUMBER_H

#include <QDialog>
#include <QGraphicsDropShadowEffect>
#include "online.h"
#include "computer.h"
#include "utils.h"

namespace Ui {
class PlayerNumber;
}

class PlayerNumber : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerNumber(QWidget *parent = 0);
    ~PlayerNumber();

    void OnControllerConnect();
    void OnControllerDisconnect();
    void SetMsgSender(MsgSender msgSender);

private slots:
    void on_twoPlayersButton_toggled(bool checked);

    void on_threePlayersButton_toggled(bool checked);

    void on_fourPlayersButton_toggled(bool checked);

    void on_computerButton_clicked();

    void on_onlineButton_clicked();

private:
    Ui::PlayerNumber *ui;
    Computer *windowComputer;
    Online *windowOnline;
    bool m_controllerConnected = false;
    MsgSender m_msgSender = nullptr;
};

#endif // PLAYERNUMBER_H
