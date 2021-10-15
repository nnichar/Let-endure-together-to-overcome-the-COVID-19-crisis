#ifndef resource_h
#define resource_h
#include<iostream>
using namespace std;

class resource
{
    string name;
    int amount;
    float rate;
public:
    static float predict;
    resource(string n,int a,float r=0)
    {
        name=n;
        amount=a;
        rate=r;
    }
    ~resource()
    {
        amount=rate=0;
    }
    void update()
    {
        if(name=="infect")
        {
            predict*=rate;
            amount+=predict;
        }
        else
            amount+=rate;
    }
    bool check()
    {
        return amount>=0;
    }
    void income(int a,float r=0)
    {
        cout << name << (a>0? " up":" down")<< endl;
        cout <<"  rate" << (r>0? " up":" down") << endl;
        amount+=a;
        rate+=r;
    }
    void print()
    {
        cout<<name<<" : "<<amount<<"\n  rate : "<<rate<<endl;
    }
    int getAmount()
    {
        return amount;
    }
};
float resource::predict=1;

#endif

