#include "scene.h"


Scene::Scene(qreal x, qreal y, int length)
 :QGraphicsScene (x, y, length, length)
{
 this->sceneSideLength=length;
}

void Scene::fillOut(qreal cellLength)
{
 cellsCount=static_cast<int>(width()/cellLength);

 for(int y=0; y<cellsCount; ++y)
	for(int x=0; x<cellsCount; ++x)
	 {
		Cell *c=new Cell(x*cellLength, y*cellLength, cellLength);
		c->setCoordinates(y, x);

		cells.push_back(c);
		addItem(c);
	 }
}

void Scene::cleanMap(bool resetWallsToo)
{
 for(auto c : cells)
	{
	 c->setValue(-1);
	 c->setParent(nullptr);
	 if((c!=start && c!=finish) && ((c->brush()!=QBrush(Qt::black) || resetWallsToo)))
		 c->setBrush(QBrush(Qt::white));
	}

 emit newStatus("Nothing");
}

void Scene::slotStartSearch()
{
 if(start && finish)
	{
	 cleanMap();

	 logic=new LogicImpl(&cells, cellsCount);
	 logic->setStartFinish(start, finish);
	 bool allowDiagonal = diagonalPolicy==Qt::Checked;
	 logic->setDiagonalPolicy(allowDiagonal);
	 logic->calcValues();

	 auto path=logic->buildPath();
	 cleanMap();
	 if(path->size()>0)
		{
		 for(auto c : *path)
			 if(c!=start)
				{
				 c->setBrush(QBrush(Qt::darkMagenta));
				 if(delay)
					QThread::msleep(delay);

				 qApp->processEvents();
				}
		 emit newStatus("Path found");
		}
	 else
		{
		 emit newStatus("Path not found");
		}

	 delete path;
	 delete logic;
	 logic=nullptr;
	}
 else
	{
	 qWarning()<<"Start or finish not set";
	}
}

void Scene::slotCleanAll()
{
 start=nullptr;
 finish=nullptr;
 bool cleanWallsToo=true;
 cleanMap(cleanWallsToo);
}

void Scene::slotSetStartCell()
{
 if(start) start->setBrush(Qt::white);
 cleanMap();

 start=qgraphicsitem_cast<Cell*>(focusItem());
 if(start)
	qDebug()<<"Received start pos: "<<this->start->getCoordinates().y()
				<<this->start->getCoordinates().x();
 else qWarning()<<"Attempt to install null to start";
}

void Scene::slotSetFinishCell()
{
 if(finish) finish->setBrush(Qt::white);
 cleanMap();

 finish=qgraphicsitem_cast<Cell*>(focusItem());
 if(finish)
	qDebug()<<"Received finish pos: "<<this->finish->getCoordinates().y()
				<<this->finish->getCoordinates().x();
 else qWarning()<<"Attempt to install null to finish";
}

void Scene::slotSetDiagonalPolicy(int policy)
{
 diagonalPolicy=policy;
}

void Scene::slotSetDelay(int value)
{
 delay=static_cast<unsigned>(value);
 logic->delay=delay;
}

void Scene::slotSave(const QString &path)
{
 QFile *file=new QFile(path);
 if(file->open(QFile::WriteOnly))
	{
	 QTextStream stream(file);
	 stream<<cellsCount<<endl;
	 auto curCell=cells.begin();
	 QString line;
	 for(int i=0; i<cellsCount; ++i)
		{
		 for(int j=0; j<cellsCount; ++j, ++curCell)
			{
			 if((*curCell)->brush()==QBrush(Qt::black))
				{
				 line+="#";
				}
			 else
				{
				 line+=" ";
				}
			}
		 stream<<line<<endl;
		 line="";
		}

	 file->close();
	 delete file;
	 emit newStatus("The pattern saved");
	}
 else
	{
	 emit newStatus("Couldn't open the file");
	}
}

void Scene::slotUpload(const QString &path)
{
 QFile *file=new QFile(path);
 if(file->open(QFile::ReadOnly))
	{
	 QTextStream stream(file);
	 QString line;
	 line=stream.readLine();
	 int patternSize=line.toInt();
	 auto curCell=cells.begin();
	 if(cellsCount==patternSize)
		{
		 for(int i=0; i<patternSize; ++i)
			{
			 line=stream.readLine();
			 for(int j=0; j<patternSize; ++j, ++curCell)
				{
				 if(line[j]=="#")
					{
					 (*curCell)->setBrush(QBrush(Qt::black));
					}
				 else
					{
					 (*curCell)->setBrush(QBrush(Qt::white));
					}
				}
			}
		 emit newStatus("A pattern uploaded");
		}
	 else
		{
		 emit newStatus("Couldn't use the pattern: sizes do not match");
		}
	 file->close();
	 delete file;
	}
 else
	{
	 emit newStatus("Couldn't open the file");
	}
}
