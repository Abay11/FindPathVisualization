#include "cell.h"

bool Cell::isSpacePressed=false;
bool Cell::isCPressed=false;

Cell::Cell(qreal x, qreal y, qreal length)
 :QGraphicsRectItem (x, y, length, length)
{
 setAcceptHoverEvents(true);
 setFlag(QGraphicsItem::ItemIsFocusable, true);
 setFocus(Qt::FocusReason::MouseFocusReason);
}

void Cell::keyPressEvent(QKeyEvent *pe)
{
 if(pe->key()==Qt::Key_Space)
	{
	isSpacePressed=!isSpacePressed;

	isCPressed=false;
	}
 else if(pe->key()==Qt::Key_C)
	{
	 isCPressed=!isCPressed;

	 isSpacePressed=false;
	}
}

void Cell::hoverEnterEvent(QGraphicsSceneHoverEvent *pe)
{
 qDebug()<<"hover event";

	if(isSpacePressed)
	 setBrush(QBrush(Qt::black));
	else if(isCPressed)
	 setBrush(QBrush(Qt::white));

//for modifiers
// if(pe->modifiers() & Qt::ShiftModifier)
//	qDebug()<<"shift";
// else if(pe->modifiers() & Qt::ControlModifier)
//	qDebug()<<"ctrl";
// else
//	qDebug()<<"no state";
// pe->modifiers();
}
