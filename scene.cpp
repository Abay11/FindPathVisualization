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

		cells.push_back(c);
		addItem(c);
	 }
}
