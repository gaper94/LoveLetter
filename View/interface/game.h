#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QLabel>
#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QRectF>
#include "utils.h"

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

    void Update();

private:
    QLabel *userLabel;
    Ui::Game *ui;

    void setMyCard(QLabel *n,QString card_name);

};

#endif // GAME_H
