#ifndef ERATOSTHENE_H
#define ERATOSTHENE_H
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <cmath>
#include <bitset>
#include <iostream>
#include <QMessageBox>
#include <QElapsedTimer>

using namespace std;
class Eratosthene : public QThread
{
    Q_OBJECT
public:
    Eratosthene(int numberOfElements);
    int n;
    QMessageBox msgBox;
    int x = 3;
    int xx = 3;
    bitset<500001> Primes;
    QList<int> listofresults;
    QString string;
    QElapsedTimer timer;

private slots:
    void run() override;
signals:
    void RefreshProgressBarEratosthene(int i);
    void ChangelabelResultName(QString string);
    void ChangelabelEstimatedTimeEratosthene(QString string);
    void SetProgresBarEratostheneMinimum(int i);
    void SetProgresBarEratostheneMaximum(int i);
};

#endif // ERATOSTHENE_H
