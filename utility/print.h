#ifndef print_h
#define print_h
#include <iostream>
#include <unistd.h>
using namespace std;
void print(string a)
{
    for(unsigned int i=0; i<a.size(); i++)
    {
        cout<<a[i];
        //usleep(1);
    }
    cout<<endl;
    usleep(1000);
}
#endif // print_h
