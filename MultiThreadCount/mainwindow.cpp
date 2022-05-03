#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QString"
#include "QTimeLine"
#include "QTimer"
#include "QDebug"

MainWindow * MainWindow::pMainWindow = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBarFactorial->setValue(0);
    pMainWindow = this;

}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow *MainWindow::getMainWinPtr()
{
    return pMainWindow;
}


void MainWindow::on_pushButtonStartFact_clicked()
{
    QString inputPar = ui->FactInput->toPlainText();
    int inputParint = inputPar.toInt();
    fact = new Factorial(inputParint);
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
    fact->start();
}

void MainWindow::on_pushButtonStartEratosthene_clicked()
{
    QString inputPar = ui->EratostheneInput->toPlainText();
    int inputParint = inputPar.toInt();
    eratosthene = new Eratosthene(inputParint);
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
    eratosthene->start();
}
