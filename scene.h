#ifndef SCENE_H
#define SCENE_H

#include "cell.h"
#include "logicimpl.h"

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QThread>
#include <QFile>

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
 LogicImpl *logic=nullptr;

public:
 unsigned delay=0;

 Scene(qreal x, qreal y, int sceneSideLength);
 void fillOut(qreal cellLength);
 void cleanMap(bool resetWallsToo=false);

 public slots:
 void slotStartSearch();
 void slotCleanAll();
 void slotSetStartCell();
 void slotSetFinishCell();
 void slotSetDiagonalPolicy(int policy);
 void slotSetDelay(int value);
 void slotSave(const QString &path);
 void slotUpload(QStringList *lines);

signals:
 void newStatus(QString text);

};

#endif // SCENE_H
