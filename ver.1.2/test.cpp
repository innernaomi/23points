#include <iostream>
#include "unit.h"
using std::cout;
using std::cin;
using std::endl;
int main(){
    units m;
    m.first_all();
    m.test(1);
    m.error(1);
    m.choose(23);
    m.choose(1);
    m.result();
}