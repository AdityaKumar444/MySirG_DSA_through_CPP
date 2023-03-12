#include<bits/stdc++.h>
using namespace std ; 
struct node
{
    int data ;
    int priority ;
    node *next ;
};
class PriorityQueue
{
    private:
        node *start ;
    public:
        PriorityQueue();
        void insert(int,int);
        void Delete();
        int getElement();
        int getHighestPriority();
        bool isEmpty();
        node * getStart();
        ~PriorityQueue();
};
PriorityQueue::PriorityQueue()
{
    start = NULL ;
}
void PriorityQueue::insert(int value , int order)
{
    node *x = new node ;
    x->data = value ;
    x->priority = order ;
    if(isEmpty())
    {
        x->next = NULL ;
        start = x ;
    }
    else
    {
        if(order > start->priority)
        {
            x->next = start ;
            start = x ;
        }
        else if(order == start->priority)
        {
            x->next = start->next ;
            start->next = x ;
        }
        else
        {
            node *t = start ;
            while(t->next!=NULL)
            {
                if(order <= t->next->priority)
                    t = t->next ;
                else
                    break;
            }
            x->next = t->next ;
            t->next = x ;
        }
    }
}
void PriorityQueue::Delete()
{
    if(!isEmpty())
    {
        node *temp = start ;
        start = start->next ;
        delete temp ;
    }
}
int PriorityQueue::getElement()
{
    if(!isEmpty())
        return start->data ;
    return INT_MIN ;
}
int PriorityQueue::getHighestPriority()
{
    if(!isEmpty())
        return start->priority ;
    return INT_MIN;
}
bool PriorityQueue::isEmpty()
{
    if(start==NULL)
        return true ;
    return false ;
}
node * PriorityQueue::getStart()
{
    return start ;
}
PriorityQueue::~PriorityQueue()
{
    while(start!=NULL)
        Delete();
}
