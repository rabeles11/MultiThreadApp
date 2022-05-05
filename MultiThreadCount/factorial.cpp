#include "factorial.h"
#include "QDebug"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QString"
#include <sstream>
#include <iomanip>
#include <limits>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
#include "QTimeLine"
#include "QTimer"
#include "mainwindow.h"

Factorial::Factorial(int numberOfElements)
{
    n = numberOfElements;
}

QString longDoubleToString(long double value)
    {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << value;
    return QString::fromStdString(stream.str());
    }

void Factorial::run()
{

    if (n < 0){
        msgBox.setText("The N < 0");
        msgBox.exec();
    }
    else {
        emit ChangelabelResultName("Counting");
        emit SetProgresBarFactorialMinimum(1);
        emit SetProgresBarFactorialMaximum(n);
        for(int i = x; i <= n; ++i) {
            timer.start();
            factorial *= i;
            sleep(1);
            x = i;
            emit RefreshProgressBar(i);
            emit ChangelabelEstimatedTimeFact(QString::number(timer.elapsed() * (n-i))+"ms");
        }
            emit ChangelabelResultName(longDoubleToString(factorial));
        }
}
