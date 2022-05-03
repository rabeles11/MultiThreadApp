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
private slots:
    void run() override;
};

#endif // FACTORIAL_H
