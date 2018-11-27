#include "scene.h"


Scene::Scene(qreal x, qreal y, qreal length)
 :QGraphicsScene (x, y, length, length)
{
}

void Scene::fillOut(qreal length)
{
 int sideLength=static_cast<int>(width()/length);

 for(int i=0; i<sideLength; ++i)
	for(int j=0; j<sideLength; ++j)
	 {
		Cell *c=new Cell(i*length, j*length, length);
		c->setCoordinates(i, j);

		cells.push_back(c);
		addItem(c);
	 }
}

void Scene::slotCleanAll()
{
 for(auto c : cells)
	{
	 c->setBrush(QBrush(Qt::white));
	}
}

void Scene::slotSetStartCell()
{
 start=qgraphicsitem_cast<Cell*>(focusItem());
 if(start)
	qDebug()<<"Received start pos: "<<this->start->getCoordinates().y()
				<<this->start->getCoordinates().x();
}

void Scene::slotSetFinishCell()
{
 finish=qgraphicsitem_cast<Cell*>(focusItem());
 if(finish)
	qDebug()<<"Received finish pos: "<<this->finish->getCoordinates().y()
				<<this->finish->getCoordinates().x();
}
