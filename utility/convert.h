#ifndef convert_h
#define convert_h

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;

int strtoi(string x)
{
    int sum=0;
    for(unsigned int i=0; i<x.size(); i++)
    {
        sum*=10;
        sum+=x[i]-'0';
    }
    return sum;
}
string itostr(int x)
{
    string s;
    stringstream temp;
    temp<<x;
    temp>>s;
    return s;
}
#endif


