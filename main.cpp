#include "view.h"
#include "widget.h"

#include <QApplication>
#include <QMainWindow>


int main(int argc, char *argv[])
{
 QApplication a(argc, argv);

 Scene *scene=new Scene(0,0,600);
 scene->fillOut(10);

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

 return a.exec();
}
