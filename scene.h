#ifndef SCENE_H
#define SCENE_H

#include "cell.h"
#include "logicimpl.h"

#include <QGraphicsScene>
#include <QKeyEvent>

class Scene : public QGraphicsScene
{
 Q_OBJECT
private:
 QVector<Cell*> cells;
 Cell *start;
 Cell *finish;
 int sceneSideLength;

public:
 Scene(qreal x, qreal y, int sceneSideLength);
 void fillOut(qreal cellSideLength);

 public slots:
 void slotStartSearch();
 void slotCleanAll();
 void slotSetStartCell();
 void slotSetFinishCell();

};

#endif // SCENE_H
