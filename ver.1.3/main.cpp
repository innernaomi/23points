#include <iostream>
#include "unit.h"
using std::cout;
using std::cin;
int main()
{
    for(int a=1;a<24;a++)
    {
        units a1;
        a1.first_all();
        if(a1[a]) a1<<a;
        else continue;
        for(int b=1;b<24;b++)
        {
            units b1=a1;
            if(b1[b]) b1<<b;
            else continue;
            for(int b=1;b<24;b++)
            {
                units c1=b1;
                if(c1[b]) c1<<b;
                else continue;
                for(int b=1;b<24;b++)
                {
                    units d1=c1;
                    if(d1[b]) d1<<b;
                    else continue;
                    for(int b=1;b<24;b++)
                    {
                        units e1=d1;
                        if(e1[b]) e1<<b;
                        else continue;
                        e1.f_result();
                    } 
                } 
            } 
        } 
    }
}