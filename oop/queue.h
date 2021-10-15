#ifndef queue_h
#define queue_h

#include "node.h"

class Q
{
    node*head;
    node*tail;
    int size;
public:
    void addNode(node*&);
    void show();
    Q();
    ~Q();
};
Q::Q()
{
    head=NULL;
    tail=NULL;
    size=0;
}
Q::~Q()
{
    int i;
    node *t;
    for(i=0; i<size; i++)
    {
        t=head;
        head=head->next();
        delete t;
    }

}

void Q::show()
{
    node* t=head;
    int i;
    for(i=0; i<size; i++)
    {
        t->show();
        cout<<" ";
        t->log::show();
        t=t->next();
    }
}
void Q::addNode(node *&A)
{
    if(size==0)
    {
        head=A;
        tail=A;
    }
    else
    {
        tail->insert(A);
        tail=A;
    }
    size++;
}
#endif // queue_h
