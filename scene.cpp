#include "scene.h"


Scene::Scene(qreal x, qreal y, int length)
 :QGraphicsScene (x, y, length, length)
{
 this->sceneSideLength=length;
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

void Scene::slotStartSearch()
{
 if(start && finish)
	{
	 LogicImpl *logic=new LogicImpl(&cells, 40);
	 logic->setStartFinish(start, finish);

	 logic->calcValues();
	 auto path=logic->buildPath();
	 for(auto c : *path)
		if(c!=start) c->setBrush(QBrush(Qt::darkMagenta));

	 delete path;
	 delete logic;
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
 for(auto c : cells)
	{
	 c->setValue(-1);
	 c->setParent(nullptr);
	 c->setBrush(QBrush(Qt::white));
	}
}

void Scene::slotSetStartCell()
{
 if(start) start->setBrush(Qt::white);

 start=qgraphicsitem_cast<Cell*>(focusItem());
 if(start)
	qDebug()<<"Received start pos: "<<this->start->getCoordinates().y()
				<<this->start->getCoordinates().x();
 else qWarning()<<"Attempt to install null to start";
}

void Scene::slotSetFinishCell()
{
 if(finish) finish->setBrush(Qt::white);

 finish=qgraphicsitem_cast<Cell*>(focusItem());
 if(finish)
	qDebug()<<"Received finish pos: "<<this->finish->getCoordinates().y()
				<<this->finish->getCoordinates().x();
 else qWarning()<<"Attempt to install null to finish";
}
