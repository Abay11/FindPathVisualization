#include "view.h"
#include "widget.h"

#include <QApplication>
#include <QMainWindow>


int main(int argc, char *argv[])
{
 QApplication a(argc, argv);

 Scene *scene=new Scene(0,0,400);
 scene->fillOut(20);

 View *v=new View;
 v->setScene(scene);

 Widget *pwidget=new Widget(v);

 QMainWindow main;
 main.setCentralWidget(pwidget);
 main.show();

 return a.exec();
}
