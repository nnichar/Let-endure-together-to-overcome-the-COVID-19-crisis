#ifndef log_h
#define log_h
#include <iostream>
using namespace std;
class log
{
    string question,answer;
public:
    log(string,string="NULL");
    void show();
};
log::log(string q,string a)
{
    question=q;
    answer=a;
    //show();
}
void log::show()
{
    if(question!="NULL")
        cout<<question<<(answer=="NULL"?"":"\n  > ");
    if(answer!="NULL")
        cout<<answer;
    cout<<endl;
}


#endif // log_h
