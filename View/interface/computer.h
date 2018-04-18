#ifndef COMPUTER_H
#define COMPUTER_H

#include <QDialog>
#include <QLineEdit>
#include <QGraphicsDropShadowEffect>
#include "game.h"
#include "utils.h"

namespace Ui {
class Computer;
}

class Computer : public QDialog
{
    Q_OBJECT

public:
    explicit Computer(QWidget *parent = 0);
    ~Computer();

    QString game_mode;

private slots:
    void on_startButton_clicked();

    void TextChanged(QString str); //teste si il y a de texte dans LineEdit

    void on_easyButton_toggled(bool checked);

    void on_mediumButton_toggled(bool checked);

    void on_hardButton_toggled(bool checked);

private:
    Ui::Computer *ui;
    Game *windowGame;
    QLineEdit *textArea;
    QPushButton *startButton;
};

#endif // COMPUTER_H
