#include <iostream>
#include "clsString.h"

using namespace std;


int main()
{
    clsString text1("Lava Hassan, Syrian, Software Developer");

    cout << text1.CountWords(" ") << endl;

    return 0;
}