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
    MainWindow * mw = MainWindow::getMainWinPtr();


    if (n < 0){
        msgBox.setText("The N < 0");
        msgBox.exec();
    }
    else {
        mw->ui->label_result_fact->setText("Counting");
        mw->ui->progressBarFactorial->setMinimum(1);
        mw->ui->progressBarFactorial->setMaximum(n);;
        for(int i = x; i <= n; ++i) {
            timer.start();
            factorial *= i;
            sleep(1);
            x = i;
            mw->ui->progressBarFactorial->setValue(i);
            mw->ui->label_estimated_time_fact->setText(QString::number(timer.elapsed() * (n-i))+"ms");
        }
            mw->ui->label_result_fact->setText(longDoubleToString(factorial));
        }
}
