#ifndef SIMPLE_H
#define SIMPLE_H

#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QCheckBox>
#include <QKeyEvent>
#include <QDebug>
#include <QFileDialog>

class Widget : public QWidget
{
 Q_OBJECT
private:
 QWidget *child;
 QHBoxLayout *controlLay;
 QHBoxLayout *phlay;
 QHBoxLayout *sliderLay;
 QVBoxLayout *pvlay;
 QSlider *delaySlider;
 QPushButton *cmdSave;
 QPushButton *cmdUpload;
 QPushButton *pcmdStart;
 QPushButton *pcmdClean;
 QLabel *status;
 QCheckBox *diagonalPolicy;

 bool isDrawing=false;
 bool isRemoving=false;
 QFileDialog *savingFileDialog;
 QFileDialog *uploadingFileDialog;

protected:
 bool eventFilter(QObject *obj, QEvent *pe) override;

public:
 explicit Widget(QWidget *child, QWidget *parent = nullptr);
 void setDelay(int value);

signals:
 void startSearch();
 void cleanAll();
 void startInstalled();
 void finishInstalled();
 void diagonalPolicyChanged(int state);
 void delayValueChanged(int value);
 void saveClicked(const QString &filePath);
 void uploadClicked(const QString &filePath);

public slots:
 void slotSetStatus(QString status);
};

#endif // SIMPLE_H
