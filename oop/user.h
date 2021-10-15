#ifndef user_h
#define user_h
#include <iostream>
#include "../data/save.h"
using namespace std;
class user
{
    string name;
    int week;
    int score;
public:
    user(string);
    ~user();
    string getName();
    void setScore(int);
    void addWeek(int=1);
    void saveRecord(ii[],string[]);
    void showResult();
};
user::user(string n)
{
    name=n;
    score=week=0;
    cout << "Hello " << name <<endl;
}
user::~user()
{
    cout<<"Bye "<<name<<endl;
}
string user::getName()
{
    return name;
}
void user::setScore(int s)
{
    score=s;
}
void user::addWeek(int x)
{
    //cout<<"==========================\n";
    while(x--)
    {
        cout<<"Week : "<<++week<<endl;
    }
}
void user::saveRecord(ii highScore[],string leader[])
{
    leader[10]=name;
    highScore[10].first=score;
    highScore[10].second=week;
}
void user::showResult()
{
    cout<<"Name : "<<name<<endl;
    cout<<" Score : "<<score<<endl;
    cout<<" Week : "<<week<<endl<<endl;

}
#endif
