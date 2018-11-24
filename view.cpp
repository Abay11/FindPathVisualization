#include "view.h"

int View::zoomRange=0;

void View::zoomIn()
{
 if(zoomRange>MAXZOOM)
	return;

 ++zoomRange;
 scale(1.1, 1.1);
}

void View::zoomOut()
{
 if(zoomRange<-MAXZOOM)
	return;

 --zoomRange;
 scale(1/1.1, 1/1.1);
}

View::View(QWidget *parent)
 : QGraphicsView(parent)
{
}

View::~View()
{

}

void View::wheelEvent(QWheelEvent *pe)
{
 if(pe->modifiers() & Qt::ControlModifier)
	{
	 if(pe->angleDelta().y()>0)
		zoomIn();
	 else
		zoomOut();
	}
}
