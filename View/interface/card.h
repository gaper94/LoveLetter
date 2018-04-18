#ifndef CARD_H
#define CARD_H

#include <QtGlobal>
#if QT_VERSION >= 0x050000
    #include <QtWidgets>
#else
    #include <QtGui>
#endif

#include <QObject>

class card:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF position READ position WRITE setPosition)

public:    
    card(const QPixmap &image, QGraphicsItem *parent=0);
    virtual ~card();

    void setPosition(QPointF position);
    QPointF position() const;

private:
    QPointF _offset;
    QPointF _pos;
};

#endif // CARD_H
