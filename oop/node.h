#ifndef node_h
#define node_h
#include "log.h"
class node:public log
{
    int i;
    node* next_ptr;
public:
    static int count;
    node(string,string);
    void show();
    void insert(node*&);
    node* next();
};
int node::count=0;
node::node(string q,string a="NULL"):log(q,a)
{
    i=(++count);
    next_ptr=NULL;
    //cerr<<"adding "<<i<<endl;
}
node* node::next()
{
    return next_ptr;
}
void  node:: show()
{
    cout<<i;
}
void node::insert(node*& x)
{
    this->next_ptr=x;

}

#endif // node_h
