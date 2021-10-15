#ifndef cmp_h
#define cmp_h
#include <iostream>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
bool iicmp(ii,ii);
void setBetween(int&,int,int);

bool iicmp(ii a,ii b)
{
    if(a.first>b.first)
        return 1;
    if(a.first==b.first)
    {
        if(a.second<b.second)
            return 1;
    }
    return 0;
}
void setBetween(int &x,int left,int right)
{
    while(x<left)
        x+=right-left+1;
    while(x>right)
        x-=right-left+1;
}
#endif // cmp_h
