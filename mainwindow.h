#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "view.h"
#include "widget.h"

#include <QWidget>

namespace Ui {
 class MainWindow;
}

class MainWindow : public QWidget
{
 Q_OBJECT

public:
 explicit MainWindow(QWidget *parent = nullptr);
 ~MainWindow();

private:
 Ui::MainWindow *ui;

public slots:
 void createNew();
};

#endif // MAINWINDOW_H
