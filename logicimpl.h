#ifndef FINDPATHIMPLEMENTATION_H
#define FINDPATHIMPLEMENTATION_H

#include "cell.h"

#include <QVector>
#include <QQueue>

class LogicImpl
{
private:
 QVector<Cell *> *cells;
 int cellsSize=0;
 int count;
 Cell *startCell;
 Cell *finishCell;
 QQueue<Cell *> unprocessed;

public:
 LogicImpl(QVector<Cell *> *cells,
					 int sideCount);
 void setStartFinish(Cell *startCell, Cell *finishCell);
 void calcValues();
 QVector<Cell *> *buildPath();
 bool isStartCell(int index);
 void appendToUnprocessed(int index);
 void updateValue(Cell *c, int index);
};

#endif // FINDPATHIMPLEMENTATION_H
