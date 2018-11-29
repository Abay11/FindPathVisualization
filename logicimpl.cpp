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
 int startX=startCell->getCoordinates().x();
 int startY=startCell->getCoordinates().y();

 //the right cell from start
 unprocessed.append(cells->at(startY*count + startX+1));
 //the down from start
 unprocessed.append(cells->at((startY+1)*count + startX));
 //the right-bottom from start
 unprocessed.append(cells->at((startY+1)*count + startX+1));

 for(auto c : unprocessed)
	{
	 int x=c->getCoordinates().x();
	 int y=c->getCoordinates().y();

	 int index=0;
	 int value=0;
//	 right
//	 index=y*count+x+1;
//	 if(index<y*count+count)
//		{
//		 value=cells->at(index)->getValue();
//		 if(value!=-1)
//			{
//			 if(c->getValue()==-1 || c->getValue()>value)
//				c->setValue(value + 1);
//			}

//		 appendToUnprocessed(index);
//		}

	 //left
//	 /*
	 index=y*count+x-1;
	 if(index>=y*count)
		{
		 value=cells->at(index)->getValue();
			 if((c->getValue()>value && c->getValue()!=-1 && value!=-1)
					|| (c->getValue()==-1 && value!=-1))
				c->setValue(value + 1);
//			}
//		 else

//			unprocessed.append(cells->at(index));

			 appendToUnprocessed(index);
//		 if(!isStartCell(index) && !unprocessed.contains(cells->at(index)))
//			unprocessed.append(cells->at(index));
		}
//		*/

	 //top
	 index=(y-1)*count+x;
	 if(index>=0)
		{
		 value=cells->at(index)->getValue();
		 if((c->getValue()>value && c->getValue()!=-1) || c->getValue()==-1)
			c->setValue(value + 1);

		 appendToUnprocessed(index);
		}


	 //down ...

	 //top left diagonal
	 index=(y-1)*count+x-1;
	 if(index>=0 && index>=(y-1)*count)
		{
		 value=cells->at(index)->getValue();
		 if((c->getValue()>value && c->getValue()!=-1 && value!=-1)
				|| (c->getValue()==-1 && value!=-1))
			c->setValue(value + 1);
		 appendToUnprocessed(index);
		}

	 /*
	 //bottom right diagonal
	 index=(y+1)*count+x+1;
	 if(index<y*count+count)
		{
		 value=cells->at(index)->getValue();
//		 if(value!=-1)
//			{
			 if((c->getValue()>value && c->getValue()!=-1) || c->getValue()==-1)
				c->setValue(value + 1);
//			}
//		 else
			 appendToUnprocessed(index);
//			unprocessed.append(cells->at(index));
		}
		*/
	}
}

void LogicImpl::buildPath()
{

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
