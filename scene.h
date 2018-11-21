#ifndef SCENE_H
#define SCENE_H

#include "cell.h"

#include <QGraphicsScene>

class Scene : public QGraphicsScene
{
private:
 QVector<Cell*> cells;
public:
 Scene(qreal x, qreal y, qreal width, qreal height);

 void fillOut(qreal cellWidth, qreal cellHeight);
};

#endif // SCENE_H
