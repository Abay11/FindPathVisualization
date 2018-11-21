#include "scene.h"

Scene::Scene(qreal x, qreal y, qreal width, qreal height)
 :QGraphicsScene (x, y, width, height)
{
}

void Scene::fillOut(qreal cellWidth, qreal cellHeight)
{
 int sideLength=static_cast<int>(width()/cellWidth);

 for(int i=0; i<sideLength; ++i)
	for(int j=0; j<sideLength; ++j)
	 {
		Cell *c=new Cell(i*cellWidth, j*cellHeight, cellWidth, cellWidth);
		cells.push_back(c);
		addItem(c);
	 }
}
