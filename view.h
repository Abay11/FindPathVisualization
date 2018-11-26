#ifndef WIDGET_H
#define WIDGET_H

#include "scene.h"

#include <QGraphicsView>
#include <QWheelEvent>

class View : public QGraphicsView
{
 Q_OBJECT
private:
 const int MAXZOOM=5;
 static int zoomRange;

 void zoomIn();
 void zoomOut();

public:
 View(QWidget *parent = nullptr);
 void wheelEvent(QWheelEvent *pe) override;
};

#endif // WIDGET_H
