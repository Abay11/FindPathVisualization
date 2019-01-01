#include "logicimpl.h"

LogicImpl::LogicImpl(QVector<Cell *> *cells, int count)
{
 this->cells=cells;
 this->count=count;
 cellsSize=cells->size();
}

void LogicImpl::setStartFinish(Cell *startCell, Cell *finishCell)
{
 this->startCell=startCell;
 this->finishCell=finishCell;
}

void LogicImpl::calcValues()
{
 startCell->setValue(0);
 unprocessed.append(startCell);

 for(int i=0; i<cellsSize; ++i)
	{
	 auto c = unprocessed.at(i);

	 if(c!=startCell && c!=finishCell)
		c->setBrush(QBrush(Qt::yellow));

	 qApp->processEvents();

	 int x=(c)->getCoordinates().x();
	 int y=(c)->getCoordinates().y();
	 int index=0;

	 //	 right
	 index=y*count+x+1;
	 if(index<y*count+count)
		{
		 updateValue(c, index);
		 appendToUnprocessed(index);
		}

	 //left
	 index=y*count+x-1;
	 if(index>=y*count)
		{
		 updateValue(c, index);
		 appendToUnprocessed(index);
		}

	 //top
	 index=(y-1)*count+x;
	 if(index>=0)
		{
		 updateValue(c, index);
		 appendToUnprocessed(index);
		}

	 //bottom
	 index=(y+1)*count+x;
	 if(index<cellsSize)
		{
		 updateValue(c, index);
		 appendToUnprocessed(index);
		}

	 //bottom right
	 index=(y+1)*count+x+1;
	 if(index<cellsSize && index<(y+1)*count+count)
		{
		 updateValue(c, index);
		 appendToUnprocessed(index);
		}

	 //bottom left
	 index=(y+1)*count+x-1;
	 if(index<cellsSize && index>=(y+1)*count)
		{
		 updateValue(c, index);
		 appendToUnprocessed(index);
		}

	 //top right
	 index=(y-1)*count+x+1;
	 if(x<count-1 && index>=0 && index<=(y-1)*count+count)
		{
		 updateValue(c, index);
		 appendToUnprocessed(index);
		}

	 //top left
	 index=(y-1)*count+x-1;
	 if(index>=0 && index>=(y-1)*count)
		{
		 updateValue(c, index);
		 appendToUnprocessed(index);
		}

	 if(c==finishCell)
		 return;
	}
}

QVector<Cell *> *LogicImpl::buildPath()
{
 QVector<Cell *> *path=new QVector<Cell *>;
 path->append(finishCell->getParent());
 for(int i=0, size=path->size(); i<size; ++i, size=path->size())
	if(path->at(i)->getParent())
		path->append(path->at(i)->getParent());

 return path;
}

bool LogicImpl::isStartCell(int index)
{
 return startCell==cells->at(index);
}

void LogicImpl::appendToUnprocessed(int index)
{
 if(!isStartCell(index) && !unprocessed.contains(cells->at(index)))
	unprocessed.append(cells->at(index));
}

void LogicImpl::updateValue(Cell *c, int index)
{
 int value=cells->at(index)->getValue();
 if(value!=-1)
	if(c->getValue()==-1 || c->getValue()>value+1)
	 {
		c->setValue(value + 1);
		c->setParent(cells->at(index));
	 }
}
