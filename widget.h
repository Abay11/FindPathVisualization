#ifndef SIMPLE_H
#define SIMPLE_H

#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
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
 QLabel *status;
 QCheckBox *diagonalPolicy;

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
 void diagonalPolicyChanged(int state);

public slots:
 void slotSetStatus(QString status);
};

#endif // SIMPLE_H
