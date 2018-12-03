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

 QPoint xyPos;
 int value=-1;
 Cell *parent=nullptr;

public:
 Cell(qreal x, qreal y, qreal cellSideLength);
 void setCoordinates(int y, int x);
 const QPoint& getCoordinates() const;
 void setValue(int value);
 int getValue();

 void setParent(Cell *parent);
 Cell *getParent();

 void keyPressEvent(QKeyEvent *event) override;
 void hoverEnterEvent(QGraphicsSceneHoverEvent *pe) override;
};

#endif // CELL_H
