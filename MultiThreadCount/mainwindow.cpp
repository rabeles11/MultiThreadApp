#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QString"

MainWindow * MainWindow::pMainWindow = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    Factorial *fact = new Factorial(inputParint);
    fact->start();
}

