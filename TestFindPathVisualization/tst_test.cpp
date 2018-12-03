#include <QtTest>

// add necessary includes here
#include "../logicimpl.h"
#include "../cell.h"
#include "../cell.h"

class test : public QObject
{
 Q_OBJECT

public:
 test();
 ~test();

private slots:
 void test_setAndGetCoordinates1();
 void test_calcValues1();
 void test_calcValues2();
 void test_calcValues3();
 void test_calcValues4();
 void test_calcValues5();
 void test_calcValues6();
 void test_calcValues7();
 void test_calcValues8();
 void test_calcValues9();
 void test_calcValues10();
 void test_calcValues11();
 void test_calcValues12();

 void test_buildPath1();
 void test_buildPath2();
 void test_buildPath3();
 void test_buildPath4();
};

test::test()
{

}

test::~test()
{

}

void test::test_setAndGetCoordinates1()
{
 Cell c(0,0,0);
 c.setCoordinates(77, 33);
 QCOMPARE(c.getCoordinates().x(), 33);
 QCOMPARE(c.getCoordinates().y(), 77);

 Cell c2(0,0,0);
 c.setCoordinates(100, 200);
 QCOMPARE(c.getCoordinates().y(), 100);
 QCOMPARE(c.getCoordinates().x(), 200);
}

void test::test_calcValues1()
{
 //2x2
 QVector<Cell *> cells;
 for(int i=0; i<2; ++i)
	for(int j=0; j<2; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, 2);
 logic.setStartFinish(cells[0], cells[3]);
 logic.calcValues();

 QCOMPARE(cells[0]->getValue(), 0);
 QCOMPARE(cells[1]->getValue(), 1);
 QCOMPARE(cells[2]->getValue(), 1);
 QCOMPARE(cells[3]->getValue(), 1);

 for(auto c : cells)
	delete c;
}

void test::test_calcValues2()
{
 //2x2
 QVector<Cell *> cells;
 for(int i=0; i<2; ++i)
	for(int j=0; j<2; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, 2);
 logic.setStartFinish(cells[1], cells[3]);
 logic.calcValues();

 QCOMPARE(cells[0]->getValue(), 1);
 QCOMPARE(cells[1]->getValue(), 0);
 QCOMPARE(cells[2]->getValue(), 1);
 QCOMPARE(cells[3]->getValue(), 1);

 for(auto c : cells)
	delete c;
}

void test::test_calcValues3()
{
 //2x2
 QVector<Cell *> cells;
 for(int i=0; i<2; ++i)
	for(int j=0; j<2; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, 2);
 logic.setStartFinish(cells[2], cells[3]);
 logic.calcValues();

 QCOMPARE(cells[0]->getValue(), 1);
 QCOMPARE(cells[1]->getValue(), 1);
 QCOMPARE(cells[2]->getValue(), 0);
 QCOMPARE(cells[3]->getValue(), 1);

 for(auto c : cells)
	delete c;
}

void test::test_calcValues4()
{
 //2x2
 QVector<Cell *> cells;
 for(int i=0; i<2; ++i)
	for(int j=0; j<2; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, 2);
 logic.setStartFinish(cells[3], cells[0]);
 logic.calcValues();

 QCOMPARE(cells[0]->getValue(), 1);
 QCOMPARE(cells[1]->getValue(), 1);
 QCOMPARE(cells[2]->getValue(), 1);
 QCOMPARE(cells[3]->getValue(), 0);

 for(auto c : cells)
	delete c;
}

void test::test_calcValues5()
{
 //3x3
 QVector<Cell *> cells;
 for(int i=0; i<3; ++i)
	for(int j=0; j<3; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, 3);
 logic.setStartFinish(cells[4], cells[0]);
 logic.calcValues();

 QCOMPARE(cells[0]->getValue(), 1);
 QCOMPARE(cells[1]->getValue(), 1);
 QCOMPARE(cells[2]->getValue(), 1);
 QCOMPARE(cells[3]->getValue(), 1);
 QCOMPARE(cells[4]->getValue(), 0);
 QCOMPARE(cells[5]->getValue(), 1);
 QCOMPARE(cells[6]->getValue(), 1);
 QCOMPARE(cells[7]->getValue(), 1);
 QCOMPARE(cells[8]->getValue(), 1);

 for(auto c : cells)
	delete c;
}

void test::test_calcValues6()
{
 //3x3
 QVector<Cell *> cells;
 for(int i=0; i<3; ++i)
	for(int j=0; j<3; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, 3);
 logic.setStartFinish(cells[0], cells[8]);
 logic.calcValues();

 QCOMPARE(cells[0]->getValue(), 0); QCOMPARE(cells[1]->getValue(), 1); QCOMPARE(cells[2]->getValue(), 2);
 QCOMPARE(cells[3]->getValue(), 1); QCOMPARE(cells[4]->getValue(), 1); QCOMPARE(cells[5]->getValue(), 2);
 QCOMPARE(cells[6]->getValue(), 2); QCOMPARE(cells[7]->getValue(), 2); QCOMPARE(cells[8]->getValue(), 2);

 for(auto c : cells)
	delete c;
}

void test::test_calcValues7()
{
 //3x3
 QVector<Cell *> cells;
 for(int i=0; i<3; ++i)
	for(int j=0; j<3; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, 3);
 logic.setStartFinish(cells[8], cells[0]);
 logic.calcValues();

 QCOMPARE(cells[0]->getValue(), 2); QCOMPARE(cells[1]->getValue(), 2); QCOMPARE(cells[2]->getValue(), 2);
 QCOMPARE(cells[3]->getValue(), 2); QCOMPARE(cells[4]->getValue(), 1); QCOMPARE(cells[5]->getValue(), 1);
 QCOMPARE(cells[6]->getValue(), 2); QCOMPARE(cells[7]->getValue(), 1); QCOMPARE(cells[8]->getValue(), 0);

 for(auto c : cells)
	delete c;
}

void test::test_calcValues8()
{
 //4x4
 int size=4;
 QVector<Cell *> cells;
 for(int i=0; i<size; ++i)
	for(int j=0; j<size; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, size);
 logic.setStartFinish(cells[0], cells[15]);
 logic.calcValues();

 QCOMPARE(cells[0]->getValue(), 0); QCOMPARE(cells[1]->getValue(), 1); QCOMPARE(cells[2]->getValue(), 2); QCOMPARE(cells[3]->getValue(), 3);
 QCOMPARE(cells[4]->getValue(), 1); QCOMPARE(cells[5]->getValue(), 1); QCOMPARE(cells[6]->getValue(), 2); QCOMPARE(cells[7]->getValue(), 3);
 QCOMPARE(cells[8]->getValue(), 2); QCOMPARE(cells[9]->getValue(), 2); QCOMPARE(cells[10]->getValue(), 2); QCOMPARE(cells[11]->getValue(), 3);
 QCOMPARE(cells[12]->getValue(), 3); QCOMPARE(cells[13]->getValue(), 3); QCOMPARE(cells[14]->getValue(), 3); QCOMPARE(cells[15]->getValue(), 3);

 for(auto c : cells)
	delete c;
}

void test::test_calcValues9()
{
 //4x4
 int size=4;
 QVector<Cell *> cells;
 for(int i=0; i<size; ++i)
	for(int j=0; j<size; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, size);
 logic.setStartFinish(cells[3], cells[0]);
 logic.calcValues();

 QCOMPARE(cells[0]->getValue(), 3); QCOMPARE(cells[1]->getValue(), 2); QCOMPARE(cells[2]->getValue(), 1); QCOMPARE(cells[3]->getValue(), 0);
 QCOMPARE(cells[4]->getValue(), 3); QCOMPARE(cells[5]->getValue(), 2); QCOMPARE(cells[6]->getValue(), 1); QCOMPARE(cells[7]->getValue(), 1);
 QCOMPARE(cells[8]->getValue(), 3); QCOMPARE(cells[9]->getValue(), 2); QCOMPARE(cells[10]->getValue(), 2); QCOMPARE(cells[11]->getValue(), 2);
 QCOMPARE(cells[12]->getValue(), 3); QCOMPARE(cells[13]->getValue(), 3); QCOMPARE(cells[14]->getValue(), 3); QCOMPARE(cells[15]->getValue(), 3);

 for(auto c : cells)
	delete c;
}

void test::test_calcValues10()
{
 //4x4
 int size=4;
 QVector<Cell *> cells;
 for(int i=0; i<size; ++i)
	for(int j=0; j<size; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, size);
 logic.setStartFinish(cells[12], cells[3]);
 logic.calcValues();

 QCOMPARE(cells[0]->getValue(), 3); QCOMPARE(cells[1]->getValue(), 3); QCOMPARE(cells[2]->getValue(), 3); QCOMPARE(cells[3]->getValue(), 3);
 QCOMPARE(cells[4]->getValue(), 2); QCOMPARE(cells[5]->getValue(), 2); QCOMPARE(cells[6]->getValue(), 2); QCOMPARE(cells[7]->getValue(), 3);
 QCOMPARE(cells[8]->getValue(), 1); QCOMPARE(cells[9]->getValue(), 1); QCOMPARE(cells[10]->getValue(), 2); QCOMPARE(cells[11]->getValue(), 3);
 QCOMPARE(cells[12]->getValue(), 0); QCOMPARE(cells[13]->getValue(),1); QCOMPARE(cells[14]->getValue(), 2); QCOMPARE(cells[15]->getValue(), 3);

 for(auto c : cells)
	delete c;
}

void test::test_calcValues11()
{
 //4x4
 int size=4;
 QVector<Cell *> cells;
 for(int i=0; i<size; ++i)
	for(int j=0; j<size; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, size);
 logic.setStartFinish(cells[11], cells[0]);
 logic.calcValues();

 QCOMPARE(cells[0]->getValue(), 3); QCOMPARE(cells[1]->getValue(), 2); QCOMPARE(cells[2]->getValue(), 2); QCOMPARE(cells[3]->getValue(), 2);
 QCOMPARE(cells[4]->getValue(), 3); QCOMPARE(cells[5]->getValue(), 2); QCOMPARE(cells[6]->getValue(), 1); QCOMPARE(cells[7]->getValue(), 1);
 QCOMPARE(cells[8]->getValue(), 3); QCOMPARE(cells[9]->getValue(), 2); QCOMPARE(cells[10]->getValue(), 1); QCOMPARE(cells[11]->getValue(), 0);
 QCOMPARE(cells[12]->getValue(), 3); QCOMPARE(cells[13]->getValue(),2); QCOMPARE(cells[14]->getValue(), 1); QCOMPARE(cells[15]->getValue(), 1);

 for(auto c : cells)
	delete c;
}

void test::test_calcValues12()
{
 //4x4
 int size=4;
 QVector<Cell *> cells;
 for(int i=0; i<size; ++i)
	for(int j=0; j<size; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, size);
 logic.setStartFinish(cells[5], cells[15]);
 logic.calcValues();

 QCOMPARE(cells[0]->getValue(), 1); QCOMPARE(cells[1]->getValue(), 1); QCOMPARE(cells[2]->getValue(), 1); QCOMPARE(cells[3]->getValue(), 2);
 QCOMPARE(cells[4]->getValue(), 1); QCOMPARE(cells[5]->getValue(), 0); QCOMPARE(cells[6]->getValue(), 1); QCOMPARE(cells[7]->getValue(), 2);
 QCOMPARE(cells[8]->getValue(), 1); QCOMPARE(cells[9]->getValue(), 1); QCOMPARE(cells[10]->getValue(), 1); QCOMPARE(cells[11]->getValue(), 2);
 QCOMPARE(cells[12]->getValue(), 2); QCOMPARE(cells[13]->getValue(), 2); QCOMPARE(cells[14]->getValue(), 2); QCOMPARE(cells[15]->getValue(), 2);

 for(auto c : cells)
	delete c;
}

void test::test_buildPath1()
{
 //2x2
 QVector<Cell *> cells;
 for(int i=0; i<2; ++i)
	for(int j=0; j<2; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, 2);
 logic.setStartFinish(cells[0], cells[3]);
 logic.calcValues();
 logic.buildPath();

 QCOMPARE(cells[0]->getParent(), nullptr);
 QCOMPARE(cells[1]->getParent(), cells[0]);
 QCOMPARE(cells[2]->getParent(), cells[0]);
 QCOMPARE(cells[3]->getParent(), cells[0]);

 for(auto c : cells)
	delete c;
}

void test::test_buildPath2()
{
 //3x3
 QVector<Cell *> cells;
 for(int i=0; i<3; ++i)
	for(int j=0; j<3; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, 3);
 logic.setStartFinish(cells[4], cells[0]);
 logic.calcValues();
 logic.buildPath();

 QCOMPARE(cells[0]->getParent(), cells[4]);
 QCOMPARE(cells[1]->getParent(), cells[4]);
 QCOMPARE(cells[2]->getParent(), cells[4]);
 QCOMPARE(cells[3]->getParent(), cells[4]);
 QCOMPARE(cells[4]->getParent(), nullptr);
 QCOMPARE(cells[5]->getParent(), cells[4]);
 QCOMPARE(cells[6]->getParent(), cells[4]);
 QCOMPARE(cells[7]->getParent(), cells[4]);
 QCOMPARE(cells[8]->getParent(), cells[4]);

 for(auto c : cells)
	delete c;
}

void test::test_buildPath3()
{
 //3x3
 QVector<Cell *> cells;
 for(int i=0; i<3; ++i)
	for(int j=0; j<3; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, 3);
 logic.setStartFinish(cells[0], cells[8]);
 logic.calcValues();
 logic.buildPath();

 QCOMPARE(cells[8]->getParent(), cells[4]);
 QCOMPARE(cells[4]->getParent(), cells[0]);
 QCOMPARE(cells[0]->getParent(), nullptr);

 for(auto c : cells)
	delete c;
}

void test::test_buildPath4()
{
 //4x4
 int size=4;
 QVector<Cell *> cells;
 for(int i=0; i<size; ++i)
	for(int j=0; j<size; ++j)
	 {
		Cell *c=new Cell(0, 0, 0);
		c->setCoordinates(i, j);
		cells.push_back(c);
	 }

 LogicImpl logic(&cells, size);
 logic.setStartFinish(cells[12], cells[3]);
 logic.calcValues();

 QCOMPARE(cells[3]->getParent(), cells[6]);
 QCOMPARE(cells[6]->getParent(), cells[9]);
 QCOMPARE(cells[9]->getParent(), cells[12]);
 QCOMPARE(cells[12]->getParent(), nullptr);

 for(auto c : cells)
	delete c;
}


QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
