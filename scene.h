#ifndef SCENE_H
#define SCENE_H

#include "cell.h"

#include <QGraphicsScene>
#include <QKeyEvent>

class Scene : public QGraphicsScene
{
 Q_OBJECT
private:
 QVector<Cell*> cells;
public:
 Scene(qreal x, qreal y, qreal sceneSideLength);
 void fillOut(qreal cellSideLength);

 public slots:
 void slotCleanAll();

};

#endif // SCENE_H
