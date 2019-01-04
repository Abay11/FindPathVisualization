#include "scene.h"


Scene::Scene(qreal x, qreal y, int length)
 :QGraphicsScene (x, y, length, length)
{
 this->sceneSideLength=length;
}

void Scene::fillOut(qreal cellLength)
{
 cellsCount=static_cast<int>(width()/cellLength);

 for(int i=0; i<cellsCount; ++i)
	for(int j=0; j<cellsCount; ++j)
	 {
		Cell *c=new Cell(i*cellLength, j*cellLength, cellLength);
		c->setCoordinates(i, j);

		cells.push_back(c);
		addItem(c);
	 }
}

void Scene::cleanMap(bool resetWallsToo)
{
 for(auto c : cells)
	{
	 c->setValue(-1);
	 c->setParent(nullptr);
	 if((c!=start && c!=finish) && ((c->brush()!=QBrush(Qt::black) || resetWallsToo)))
		 c->setBrush(QBrush(Qt::white));
	}

 emit newStatus("Nothing");
}

void Scene::slotStartSearch()
{
 if(start && finish)
	{
	 cleanMap();

	 logic=new LogicImpl(&cells, cellsCount);
	 logic->setStartFinish(start, finish);
	 bool allowDiagonal = diagonalPolicy==Qt::Checked;
	 logic->setDiagonalPolicy(allowDiagonal);
	 logic->calcValues();

	 auto path=logic->buildPath();
	 cleanMap();
	 if(path->size()>0)
		{
		 for(auto c : *path)
			 if(c!=start)
				{
				 c->setBrush(QBrush(Qt::darkMagenta));
				 if(delay)
					QThread::msleep(delay);

				 qApp->processEvents();
				}
		 emit newStatus("Path found");
		}
	 else
		{
		 emit newStatus("Path not found");
		}

	 delete path;
	 delete logic;
	 logic=nullptr;
	}
 else
	{
	 qWarning()<<"Start or finish not set";
	}
}

void Scene::slotCleanAll()
{
 start=nullptr;
 finish=nullptr;
 bool cleanWallsToo=true;
 cleanMap(cleanWallsToo);
}

void Scene::slotSetStartCell()
{
 if(start) start->setBrush(Qt::white);
 cleanMap();

 start=qgraphicsitem_cast<Cell*>(focusItem());
 if(start)
	qDebug()<<"Received start pos: "<<this->start->getCoordinates().y()
				<<this->start->getCoordinates().x();
 else qWarning()<<"Attempt to install null to start";
}

void Scene::slotSetFinishCell()
{
 if(finish) finish->setBrush(Qt::white);
 cleanMap();

 finish=qgraphicsitem_cast<Cell*>(focusItem());
 if(finish)
	qDebug()<<"Received finish pos: "<<this->finish->getCoordinates().y()
				<<this->finish->getCoordinates().x();
 else qWarning()<<"Attempt to install null to finish";
}

void Scene::slotSetDiagonalPolicy(int policy)
{
 diagonalPolicy=policy;
}

void Scene::slotSetDelay(int value)
{
 delay=static_cast<unsigned>(value);
 logic->delay=delay;
}
