#ifndef ERATOSTHENE_H
#define ERATOSTHENE_H
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <cmath>

class Eratosthene : public QThread
{
public:
    Eratosthene();

private slots:
    void run() override;
};

#endif // ERATOSTHENE_H
