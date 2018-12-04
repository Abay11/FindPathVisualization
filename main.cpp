#include "view.h"
#include "widget.h"

#include <QApplication>
#include <QMainWindow>


int main(int argc, char *argv[])
{
 QApplication a(argc, argv);

// /*
 Scene *scene=new Scene(0,0,800);
 scene->fillOut(20);

 View *v=new View;
 v->setScene(scene);

 Widget *pwidget=new Widget(v);

 QObject::connect(pwidget, SIGNAL(cleanAll()), scene, SLOT(slotCleanAll()));
 QObject::connect(pwidget, SIGNAL(startSearch()), scene, SLOT(slotStartSearch()));
 QObject::connect(pwidget, SIGNAL(startInstalled()), scene, SLOT(slotSetStartCell()));
 QObject::connect(pwidget, SIGNAL(finishInstalled()), scene, SLOT(slotSetFinishCell()));

 QMainWindow main;
 main.setCentralWidget(pwidget);
 main.show();
// */

 /*
 int size=10;
 QVector<Cell *> cells;
 for(int i=0; i<size; ++i)
	for(int j=0; j<size; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, size);
 logic.setStartFinish(cells[0], cells[9]);
 logic.calcValues();
 auto path=logic.buildPath();
 */

 return a.exec();
}
