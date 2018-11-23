#ifndef CELL_H
#define CELL_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneHoverEvent>
#include <QKeyEvent>
#include <QBrush>
#include <QApplication>
#include <QDebug>

class Cell : public QGraphicsRectItem
{
private:
 static bool isSpacePressed;
 static bool isCPressed;

public:
 Cell(qreal x, qreal y, qreal cellSideLength);

 void keyPressEvent(QKeyEvent *event) override;
 void hoverEnterEvent(QGraphicsSceneHoverEvent *pe) override;
};

#endif // CELL_H
