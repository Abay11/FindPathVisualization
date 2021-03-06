#include "cell.h"

bool Cell::isSpacePressed=false;
bool Cell::isCPressed=false;

Cell::Cell(qreal x, qreal y, qreal length)
 : QGraphicsRectItem (x, y, length, length)
{
 setAcceptHoverEvents(true);
 setFlag(QGraphicsItem::ItemIsFocusable, true);
}

void Cell::setCoordinates(int y, int x)
{
 xyPos.ry()=y;
 xyPos.rx()=x;
}

const QPoint& Cell::getCoordinates() const
{
 return xyPos;
}

void Cell::setValue(int value)
{
 this->value=value;
}

int Cell::getValue()
{
 return value;
}

void Cell::setParent(Cell *parent)
{
 this->parent=parent;
}

Cell *Cell::getParent()
{
 return parent;
}

void Cell::keyPressEvent(QKeyEvent *pe)
{
 qDebug()<<pos().x()<<" "<<pos().y();

 if(pe->key()==Qt::Key_S)
	{
	 setBrush(QBrush(Qt::green));
	 isSpacePressed=false;
	 isCPressed=false;
	}
 else if(pe->key()==Qt::Key_F)
	{
	 setBrush(QBrush(Qt::red));
	 isSpacePressed=false;
	 isCPressed=false;
	}
 else if(pe->key()==Qt::Key_Space)
	{
	 setBrush(QBrush(Qt::black));
	 isSpacePressed=!isSpacePressed;
	 isCPressed=false;
	}
 else if(pe->key()==Qt::Key_C)
	{
	 setBrush(QBrush(Qt::white));
	 isCPressed=!isCPressed;
	 isSpacePressed=false;
	}
}

void Cell::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
 qDebug()<<"hover event";
 setFocus();

 if(isSpacePressed)
	setBrush(QBrush(Qt::black));
 else if(isCPressed)
	setBrush(QBrush(Qt::white));
}
