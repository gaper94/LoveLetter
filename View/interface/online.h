#ifndef ONLINE_H
#define ONLINE_H

#include <QDialog>
#include <QLineEdit>
#include <QGraphicsDropShadowEffect>
#include "game.h"
#include "utils.h"

namespace Ui {
class Online;
}

class Online : public QDialog
{
    Q_OBJECT

public:
    explicit Online(QWidget *parent = 0);
    ~Online();

private slots:
    void on_startButton_clicked();

    void TextChanged(QString str); //text changed

private:
    Ui::Online *ui;
    Game *windowGame;
    QPushButton *startButton;
    QLineEdit *textArea;
};

#endif // ONLINE_H
