#include "widget.h"

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
}
