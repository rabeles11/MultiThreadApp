#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QString"
#include "QTimeLine"
#include "QTimer"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBarFactorial->setValue(0);
    ui->progressBarEratosthene->setValue(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonStartFact_clicked()
{
    QString inputPar = ui->FactInput->toPlainText();
    int inputParint = inputPar.toInt();
    fact = new Factorial(inputParint);
    connect(fact, &Factorial::RefreshProgressBar,this, &MainWindow::RefreshBarFact);
    connect(fact, &Factorial::ChangelabelResultName,this, &MainWindow::ChangeLabelResultName);
    connect(fact, &Factorial::SetProgresBarFactorialMaximum,this, &MainWindow::SetProgresBarFactorialMaximum);
    connect(fact, &Factorial::SetProgresBarFactorialMinimum,this, &MainWindow::SetProgresBarFactorialMinimum);
    connect(fact, &Factorial::ChangelabelEstimatedTimeFact,this, &MainWindow::ChangelabelEstimatedTimeFact);


    fact->start();
}



void MainWindow::on_pushButtonStopFact_clicked()
{
    if(ui->pushButtonStopFact->text() == "STOP")
    {
       fact->terminate();
       ui->pushButtonStopFact->setText("RESUME");
    }
    else
    {
        fact->start();
        ui->pushButtonStopFact->setText("STOP");
    }


}

void MainWindow::on_pushButtonResetFact_clicked()
{
    fact->terminate();
    QString inputPar = ui->FactInput->toPlainText();
    int inputParint = inputPar.toInt();
    fact = new Factorial(inputParint);
    connect(fact, &Factorial::RefreshProgressBar,this, &MainWindow::RefreshBarFact);
    connect(fact, &Factorial::ChangelabelResultName,this, &MainWindow::ChangeLabelResultName);
    connect(fact, &Factorial::SetProgresBarFactorialMaximum,this, &MainWindow::SetProgresBarFactorialMaximum);
    connect(fact, &Factorial::SetProgresBarFactorialMinimum,this, &MainWindow::SetProgresBarFactorialMinimum);
    connect(fact, &Factorial::ChangelabelEstimatedTimeFact,this, &MainWindow::ChangelabelEstimatedTimeFact);
    fact->start();
}

void MainWindow::on_pushButtonStartEratosthene_clicked()
{
    QString inputPar = ui->EratostheneInput->toPlainText();
    int inputParint = inputPar.toInt();
    eratosthene = new Eratosthene(inputParint);
    connect(eratosthene, &Eratosthene::RefreshProgressBarEratosthene,this, &MainWindow::RefreshBarEratosthene);
    connect(eratosthene, &Eratosthene::ChangelabelResultName,this, &MainWindow::ChangeLabelResultNameEratosthene);
    connect(eratosthene, &Eratosthene::SetProgresBarEratostheneMaximum,this, &MainWindow::SetProgresBarEratostheneMaximum);
    connect(eratosthene, &Eratosthene::SetProgresBarEratostheneMinimum,this, &MainWindow::SetProgresBarEratostheneMinimum);
    connect(eratosthene, &Eratosthene::ChangelabelEstimatedTimeEratosthene,this, &MainWindow::ChangelabelEstimatedTimeEratosthene);
    eratosthene->start();
}

void MainWindow::on_pushButtonStopEratosthene_clicked()
{
    if(ui->pushButtonStopEratosthene->text() == "STOP")
    {
       eratosthene->terminate();
       ui->pushButtonStopEratosthene->setText("RESUME");
    }
    else
    {
        eratosthene->start();
        ui->pushButtonStopEratosthene->setText("STOP");
    }
}

void MainWindow::on_pushButtonResetEratosthene_clicked()
{
    eratosthene->terminate();
    QString inputPar = ui->EratostheneInput->toPlainText();
    int inputParint = inputPar.toInt();
    eratosthene = new Eratosthene(inputParint);
    connect(eratosthene, &Eratosthene::RefreshProgressBarEratosthene,this, &MainWindow::RefreshBarEratosthene);
    connect(eratosthene, &Eratosthene::ChangelabelResultName,this, &MainWindow::ChangeLabelResultNameEratosthene);
    connect(eratosthene, &Eratosthene::SetProgresBarEratostheneMaximum,this, &MainWindow::SetProgresBarEratostheneMaximum);
    connect(eratosthene, &Eratosthene::SetProgresBarEratostheneMinimum,this, &MainWindow::SetProgresBarEratostheneMinimum);
    connect(eratosthene, &Eratosthene::ChangelabelEstimatedTimeEratosthene,this, &MainWindow::ChangelabelEstimatedTimeEratosthene);
    eratosthene->start();
}

void MainWindow::RefreshBarFact(int i)
{
    ui->progressBarFactorial->setValue(i);
}

void MainWindow::ChangeLabelResultName(QString string)
{
    ui->label_result_fact->setText(string);
}

void MainWindow::SetProgresBarFactorialMaximum(int i)
{
    ui->progressBarFactorial->setMaximum(i);
}

void MainWindow::SetProgresBarFactorialMinimum(int i)
{
    ui->progressBarFactorial->setMinimum(i);
}

void MainWindow::ChangelabelEstimatedTimeFact(QString string)
{
    ui->label_estimated_time_fact->setText(string);
}

void MainWindow::RefreshBarEratosthene(int i)
{
    ui->progressBarEratosthene->setValue(i);
}

void MainWindow::ChangeLabelResultNameEratosthene(QString string)
{
    ui->label_result_eratosthene->setText(string);
}

void MainWindow::SetProgresBarEratostheneMaximum(int i)
{
    ui->progressBarEratosthene->setMaximum(i);
}

void MainWindow::SetProgresBarEratostheneMinimum(int i)
{
    ui->progressBarEratosthene->setMinimum(i);
}

void MainWindow::ChangelabelEstimatedTimeEratosthene(QString string)
{
    ui->label_estimated_time_eratosthene->setText(string);
}
