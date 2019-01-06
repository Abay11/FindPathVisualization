#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MainWindow)
{
 ui->setupUi(this);
}

MainWindow::~MainWindow()
{
 delete ui;
}

void MainWindow::createNew()
{
 Scene *scene=new Scene(0,0,800);
 scene->fillOut(200);

 View *v=new View;
 v->setScene(scene);

 Widget *pwidget=new Widget(v);

 QObject::connect(pwidget, SIGNAL(cleanAll()), scene, SLOT(slotCleanAll()));
 QObject::connect(pwidget, SIGNAL(startSearch()), scene, SLOT(slotStartSearch()));
 QObject::connect(pwidget, SIGNAL(startInstalled()), scene, SLOT(slotSetStartCell()));
 QObject::connect(pwidget, SIGNAL(finishInstalled()), scene, SLOT(slotSetFinishCell()));
 QObject::connect(pwidget, SIGNAL(diagonalPolicyChanged(int)), scene, SLOT(slotSetDiagonalPolicy(int)));
 QObject::connect(pwidget, SIGNAL(delayValueChanged(int)), scene, SLOT(slotSetDelay(int)));
 QObject::connect(pwidget, SIGNAL(saveClicked(const QString &)), scene, SLOT(slotSave(const QString &)));
 QObject::connect(pwidget, SIGNAL(uploadClicked(const QString &)), scene, SLOT(slotUpload(const QString &)));
 QObject::connect(scene, SIGNAL(newStatus(QString)), pwidget, SLOT(slotSetStatus(QString)));

 pwidget->setDelay(50);
}
