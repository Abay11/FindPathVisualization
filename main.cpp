#include "view.h"

#include <QApplication>

int main(int argc, char *argv[])
{
 QApplication a(argc, argv);

 Scene *scene=new Scene(0,0,100,100);
 scene->fillOut(50,50);


 View v;
 v.setScene(scene);
 v.show();

 return a.exec();
}
