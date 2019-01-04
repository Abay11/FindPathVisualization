#include "view.h"
#include "widget.h"

#include <QApplication>
#include <QMainWindow>


int main(int argc, char *argv[])
{
 QApplication a(argc, argv);

 Scene *scene=new Scene(0,0,800);
 scene->fillOut(80);

 View *v=new View;
 v->setScene(scene);

 Widget *pwidget=new Widget(v);

 QObject::connect(pwidget, SIGNAL(cleanAll()), scene, SLOT(slotCleanAll()));
 QObject::connect(pwidget, SIGNAL(startSearch()), scene, SLOT(slotStartSearch()));
 QObject::connect(pwidget, SIGNAL(startInstalled()), scene, SLOT(slotSetStartCell()));
 QObject::connect(pwidget, SIGNAL(finishInstalled()), scene, SLOT(slotSetFinishCell()));
 QObject::connect(pwidget, SIGNAL(diagonalPolicyChanged(int)), scene, SLOT(slotSetDiagonalPolicy(int)));
 QObject::connect(pwidget, SIGNAL(delayValueChanged(int)), scene, SLOT(slotSetDelay(int)));
 QObject::connect(scene, SIGNAL(newStatus(QString)), pwidget, SLOT(slotSetStatus(QString)));

 pwidget->setDelay(50);

 QMainWindow main;
 main.setCentralWidget(pwidget);
 main.show();

 return a.exec();
}
