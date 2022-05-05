#ifndef FACTORIAL_H
#define FACTORIAL_H
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <cmath>
#include <QMessageBox>
#include <QElapsedTimer>
#include <QString>


class Factorial : public QThread
{
    Q_OBJECT
public:
    Factorial(int numberOfElements);
    int n;
    QMessageBox msgBox;
    long double factorial = 1.0;
    int x = 1;
    QElapsedTimer timer;

private slots:
    void run() override;
signals:
    void RefreshProgressBar(int i);
    void ChangelabelResultName(QString string);
    void ChangelabelEstimatedTimeFact(QString string);
    void SetProgresBarFactorialMinimum(int i);
    void SetProgresBarFactorialMaximum(int i);
};

#endif // FACTORIAL_H
