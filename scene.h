#ifndef SCENE_H
#define SCENE_H

#include "cell.h"
#include "logicimpl.h"

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QThread>

class Scene : public QGraphicsScene
{
 Q_OBJECT
private:
 QVector<Cell*> cells;
 Cell *start=nullptr;
 Cell *finish=nullptr;
 int sceneSideLength;
 int cellsCount;
 int diagonalPolicy=Qt::Checked;

public:
 unsigned sleep=0;

 Scene(qreal x, qreal y, int sceneSideLength);
 void fillOut(qreal cellLength);
 void cleanMap(bool resetWallsToo=false);

 public slots:
 void slotStartSearch();
 void slotCleanAll();
 void slotSetStartCell();
 void slotSetFinishCell();
 void slotSetDiagonalPolicy(int policy);

signals:
 void newStatus(QString text);

};

#endif // SCENE_H
