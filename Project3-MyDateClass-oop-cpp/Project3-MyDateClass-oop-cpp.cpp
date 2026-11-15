#include <iostream>
#include "clsDate.h"
#include "clsPeriod.h"
using namespace std;


int main()
{
    clsDate date1(360, 2026);
    date1.Print();
   cout<< date1.DaysInMonth();
    return 0;
}