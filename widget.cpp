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
			status->setText("Status: Drawing wall");
		 else
			status->setText("Status: Nothing");
		}
	 else if(keyEvent->key()==Qt::Key_C)
		{
		 isRemoving=!isRemoving;
		 isDrawing=false;
		 if(isRemoving)
			status->setText("Status: Removing wall");
		 else
			status->setText("Status: Nothing");
		}
	 else if(keyEvent->key()==Qt::Key_S)
		{
		 emit startInstalled();
		}
	 else if(keyEvent->key()==Qt::Key_F)
		{
		 emit finishInstalled();
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
 status=new QLabel("Status: No actions");
 diagonalPolicy=new QCheckBox("Allow diagonal", this);
 diagonalPolicy->setCheckState(Qt::Checked);

 phlay->addWidget(pcmdStart);
 phlay->addWidget(pcmdClean);
 phlay->addWidget(diagonalPolicy);
 phlay->addWidget(status);

 pvlay->addWidget(child);
 pvlay->addLayout(phlay);

 setLayout(pvlay);
 qApp->installEventFilter(this);

 connect(pcmdStart, SIGNAL(clicked()), SIGNAL(startSearch()));
 connect(pcmdClean, SIGNAL(clicked()), SIGNAL(cleanAll()));
 connect(diagonalPolicy, SIGNAL(stateChanged(int)), SIGNAL(diagonalPolicyChanged(int)));
}

void Widget::slotSetStatus(QString status)
{
 this->status->setText(status);
}
