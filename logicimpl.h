#ifndef FINDPATHIMPLEMENTATION_H
#define FINDPATHIMPLEMENTATION_H

#include "cell.h"

#include <QVector>

class LogicImpl
{
private:
 QVector<Cell*> *cells;
 const Cell* startCell;
 const Cell* finishCell;

public:
 LogicImpl(QVector<Cell*> *cells);

private:
 void calcValues();
 void buildPath();
};

#endif // FINDPATHIMPLEMENTATION_H
