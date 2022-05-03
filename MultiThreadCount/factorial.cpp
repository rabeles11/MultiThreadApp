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

Factorial::Factorial(int numberOfElements)
{
    n = numberOfElements;
}

QString longDoubleToString(long double value)
    {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << value;
    return QString::fromStdString(stream.str());
    }

void Factorial::run()
{
    long double factorial = 1.0;
    MainWindow * mw = MainWindow::getMainWinPtr();


    if (n < 0){
        msgBox.setText("The N < 0");
        msgBox.exec();
    }
    else {
        for(int i = 1; i <= n; ++i) {
            factorial *= i;
            sleep(1);
        }
            mw->ui->label_result_fact->setText(longDoubleToString(factorial));
            // Tadz napojit timer
        }
}
