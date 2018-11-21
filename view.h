#ifndef WIDGET_H
#define WIDGET_H

#include "scene.h"

#include <QGraphicsView>

class View : public QGraphicsView
{
 Q_OBJECT

public:
 View(QWidget *parent = 0);
 ~View();
};

#endif // WIDGET_H
