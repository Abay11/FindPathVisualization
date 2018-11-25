#ifndef SIMPLE_H
#define SIMPLE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>


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

public:
 explicit Widget(QWidget *child, QWidget *parent = nullptr);

signals:

public slots:
};

#endif // SIMPLE_H
