#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <factorial.h>
#include <eratosthene.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    QTimer *timer;
    Factorial *fact;
    Eratosthene *eratosthene;
private slots:
    void on_pushButtonStartFact_clicked();
    void on_pushButtonStopFact_clicked();
    void on_pushButtonResetFact_clicked();
    void on_pushButtonStartEratosthene_clicked();
    void on_pushButtonStopEratosthene_clicked();
    void on_pushButtonResetEratosthene_clicked();
public slots:
    void RefreshBarFact(int i);
    void ChangeLabelResultName(QString string);
    void SetProgresBarFactorialMaximum(int i);
    void SetProgresBarFactorialMinimum(int i);
    void ChangelabelEstimatedTimeFact(QString string);
    void RefreshBarEratosthene(int i);
    void ChangeLabelResultNameEratosthene(QString string);
    void SetProgresBarEratostheneMaximum(int i);
    void SetProgresBarEratostheneMinimum(int i);
    void ChangelabelEstimatedTimeEratosthene(QString string);
};
#endif // MAINWINDOW_H
