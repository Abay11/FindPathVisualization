#ifndef FINDPATHIMPLEMENTATION_H
#define FINDPATHIMPLEMENTATION_H

#include "cell.h"

#include <QVector>
#include <QQueue>
#include <QApplication>
#include <QThread>

class LogicImpl
{
private:
 QVector<Cell *> *cells;
 int cellsSize=0;
 int count;
 Cell *startCell=nullptr;
 Cell *finishCell=nullptr;
 QQueue<Cell *> unprocessed;
 bool allowDiagonal=true;

public:
 static unsigned delay;

 LogicImpl(QVector<Cell *> *cells,
					 int sideCount);
 void setStartFinish(Cell *startCell, Cell *finishCell);
 void calcValues();
 QVector<Cell *> *buildPath();
 bool isStartCell(int index);
 bool isWall(int index);
 void appendToUnprocessed(int index);
 void updateValue(Cell *c, int index);
 void setDiagonalPolicy(bool policy);
};

#endif // FINDPATHIMPLEMENTATION_H
