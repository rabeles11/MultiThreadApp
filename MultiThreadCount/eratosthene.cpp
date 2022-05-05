#include "eratosthene.h"
#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "QDebug"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
Eratosthene::Eratosthene(int numberOfElements)
{
    n = numberOfElements;
}

void Eratosthene::run()
{
    Primes[0] = 1;
    emit ChangelabelResultName("Counting");
    emit SetProgresBarEratostheneMinimum(1);
    emit SetProgresBarEratostheneMaximum(n);
        for (int i = x; i*i <= n; i += 2) {
            x = i;
            if (Primes[i / 2] == 0) {
                for (int j = 3 * i; j <= n; j += 2 * i)
                    Primes[j / 2] = 1;
            }
        }
        for (int i = xx; i <= n; i++) {
            emit RefreshProgressBarEratosthene(i);
            timer.start();
            xx = i;
            sleep(1);
               if (i == 2){
                   listofresults.append(i);
               }
               else if (i % 2 == 1 && Primes[i / 2] == 0){
                   listofresults.append(i);
               }
           emit ChangelabelEstimatedTimeEratosthene(QString::number(timer.elapsed() * (n-i))+"ms");
           }

  for(int i=0; i<listofresults.size(); i++)
  {
      string += QString::number(listofresults[i]);
      if(i<listofresults.size()-1)
      string += "," ;
  }
  emit ChangelabelResultName(string);
}
