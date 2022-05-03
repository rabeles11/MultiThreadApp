#ifndef ERATOSTHENE_H
#define ERATOSTHENE_H
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <cmath>
#include <bitset>
#include <iostream>
#include <QMessageBox>
using namespace std;
class Eratosthene : public QThread
{
public:
    Eratosthene(int numberOfElements);
    int n;
    QMessageBox msgBox;
    //long double factorial = 1.0;
    int x = 1;
    bitset<500001> Primes;
private slots:
    void run() override;
};

#endif // ERATOSTHENE_H
