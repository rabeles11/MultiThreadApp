#ifndef FACTORIAL_H
#define FACTORIAL_H
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <cmath>
#include <QMessageBox>


class Factorial : public QThread
{
public:
    Factorial(int numberOfElements);
    int n;
    QMessageBox msgBox;
    long double factorial = 1.0;
    int x = 1;
private slots:
    void run() override;
};

#endif // FACTORIAL_H
