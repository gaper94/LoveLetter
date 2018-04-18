#include "card.h"

card::card(const QPixmap &image, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(image, parent), _offset(-image.width()/2, -image.height()/2), _pos()
{
    setOffset(_offset);
}

card::~card(){}

void card::setPosition(QPointF position)
{
    _pos = position;
    setOffset(_pos + _offset);
}

QPointF card::position() const
{
    return _pos;
}
