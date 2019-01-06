#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MainWindow)
{
 ui->setupUi(this);
 ui->spinBox->setRange(2, 100);
 ui->spinBox->setValue(10);
 ui->spinBox->setSingleStep(5);
}

std::pair<Widget *, Scene *> MainWindow::createNew(int cellCount)
{
 Scene *scene=new Scene(0,0,800);
 int oneCellPixelsSize=800/cellCount;
 scene->fillOut(oneCellPixelsSize);

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
 return std::make_pair(pwidget, scene);
}

MainWindow::~MainWindow()
{
 delete ui;
}

void MainWindow::slotCreateNew()
{
 Widget *w=createNew(ui->spinBox->value()).first;
 w->show();
}


void MainWindow::slotLoadFromFile()
{
 auto path=QFileDialog::getOpenFileName();
 QFile *file=new QFile(path);
 if(file->open(QFile::ReadOnly))
	{
	 QTextStream stream(file);
	 QString line;
	 line=stream.readLine();
	 int patternSize=line.toInt();
	 QStringList *lines=new QStringList;
	 lines->reserve(patternSize);
	 while(!(line=stream.readLine()).isEmpty())
		{
		 lines->append(line);
		}

	 auto widgetScenePair=createNew(patternSize);
	 auto w = widgetScenePair.first;
	 auto s = widgetScenePair.second;
	 s->slotUpload(lines);

	 w->show();
	}

	delete file;
}
