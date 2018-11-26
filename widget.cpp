#include "widget.h"

bool Widget::eventFilter(QObject *obj, QEvent *pe)
{
 if(pe->type()==QEvent::KeyPress)
	{
	 QKeyEvent *keyEvent=static_cast<QKeyEvent *>(pe);
	 if(keyEvent->key()==Qt::Key_Space)
		{
		 isDrawing=!isDrawing;
		 isRemoving=false;

		 if(isDrawing)
			ptextInfo->setText("Status: Drawing wall");
		 else
			ptextInfo->setText("Status: Nothing");
		}
	 else if(keyEvent->key()==Qt::Key_C)
		{
		 isRemoving=!isRemoving;
		 isDrawing=false;
		 if(isRemoving)
			ptextInfo->setText("Status: Removing wall");
		 else
			ptextInfo->setText("Status: Nothing");
		}
	}

 return QObject::eventFilter(obj, pe);
}

Widget::Widget(QWidget *child, QWidget *parent)
 :QWidget(parent),
	 child(child),
	 phlay(new QHBoxLayout),
	 pvlay(new QVBoxLayout)
{
 pcmdStart=new QPushButton("Start search");
 pcmdClean=new QPushButton("Clean all");
 ptextInfo=new QLabel("Status: No actions");

 phlay->addWidget(pcmdStart);
 phlay->addWidget(pcmdClean);
 phlay->addWidget(ptextInfo);

 pvlay->addWidget(child);
 pvlay->addLayout(phlay);

 setLayout(pvlay);
 qApp->installEventFilter(this);
}
