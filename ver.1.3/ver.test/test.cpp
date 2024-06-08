#include <iostream>
#include "unit.h"
using std::cout;
using std::endl;
int main()
{
    units m;
    m.first_all();
    m.test(1);
    int a[8]={23,22,21,16,12,18,15,20};
    m<<23;
    m<<22;
    m<<21;
    m<<16;
    units n=m;
    n<<12;
    n<<18;
    n<<15;
    n<<20;
    m.result();
    n.result();
    n.check_units(1);
}