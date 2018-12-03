#ifndef SIMPLE_H
#define SIMPLE_H

#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QDebug>

class Widget : public QWidget
{
 Q_OBJECT
private:
 QWidget *child;
 QHBoxLayout *phlay;
 QVBoxLayout *pvlay;
 QPushButton *pcmdStart;
 QPushButton *pcmdClean;
 QLabel *ptextInfo;

 bool isDrawing=false;
 bool isRemoving=false;

protected:
 bool eventFilter(QObject *obj, QEvent *pe) override;

public:
 explicit Widget(QWidget *child, QWidget *parent = nullptr);

signals:
 void startSearch();
 void cleanAll();
 void startInstalled();
 void finishInstalled();

public slots:
};

#endif // SIMPLE_H
