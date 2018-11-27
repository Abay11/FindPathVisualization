#ifndef CELL_H
#define CELL_H

#include <QObject>
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

 QPoint xyPos{-1,-1};
 int value=-1;

public:
 Cell(qreal x, qreal y, qreal cellSideLength);
 void setCoordinates(int x, int y);
 const QPoint getCoordinates();

 void keyPressEvent(QKeyEvent *event) override;
 void hoverEnterEvent(QGraphicsSceneHoverEvent *pe) override;
};

#endif // CELL_H
