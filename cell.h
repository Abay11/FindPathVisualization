#ifndef CELL_H
#define CELL_H

#include <QGraphicsRectItem>

class Cell : public QGraphicsRectItem
{
public:
 Cell(qreal x, qreal y, qreal cellSideLength);
};

#endif // CELL_H
