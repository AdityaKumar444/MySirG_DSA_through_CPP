#include<bits/stdc++.h>
using namespace std ; 
struct node
{
    node *prev ;
    int data ;
    node *next ;
};
class CDLL
{
    private:
        node *start ;
    public:
        CDLL() { start = NULL ; }
        void insertAtStart(int);
        void insertAtLast(int);
        node * search(int);
        void insertAfter(node *,int);
        void deleteFirst();
        void deleteLast();
        void deleteSpecific(node *);
        void display();
        ~CDLL()
        {
            while(start!=NULL)
                deleteLast();
        }
};
void CDLL::insertAtStart(int item)
{
    node *n = new node ;
    n->data = item ;
    if(start==NULL)
    {
        n->prev = n ;
        n->next = n ;
    }
    else
    {
        n->prev = start->prev ;
        n->next = start ;
        start->prev->next = n ;
        start->prev = n ;
    }
    start = n ;
}
void CDLL::insertAtLast(int item)
{
    node *n = new node ;
    n->data = item ;
    if(start==NULL)
    {
        n->prev = n ;
        n->next = n ;
        start = n ;
    }
    else
    {
        n->prev = start->prev ;
        n->next = start ;
        start->prev->next = n ;
        start->prev = n ;
    }
}
node * CDLL::search(int item)
{
    node *t ;
    t = start ;
    if(t!=NULL)
    {
        do
        {
            if(t->data==item)
                return t ;
            t = t->next ;
        } while (t!=start);
    }
    return NULL ;
}
void CDLL::insertAfter(node *t , int item)
{
    if(t!=NULL)
    {
        node *n = new node ;
        n->data = item ;
        n->prev = t ;
        n->next = t->next ;
        t->next->prev = n ;
        t->next = n ;
    }
}
void CDLL::deleteFirst()
{
    if(start!=NULL)
    {
        node *t = start ;
        if(t->next==t->next->prev)
            start = NULL ;
        else
        {
            t->prev->next = t->next ;
            t->next->prev = t->prev ;
            start = t->next ;
        }
        delete t ;
    }
}
void CDLL::deleteLast()
{
    if(start!=NULL)
    {
        node *t = start->prev ;
        if(t->next==t->next->prev)
            start = NULL ;
        else
        {
            t->prev->next = t->next ;
            t->next->prev = t->prev ;
        }
        delete t ;
    }
}
void CDLL::deleteSpecific(node *t)
{
    if(start!=NULL && t!=NULL)
    {
        if(t->next==t->next->prev)
            start = NULL ;
        else if(t==start)
            start = t->next ; 
        t->prev->next = t->next ;
        t->next->prev = t->prev ;
        delete t ;
    }
}
void CDLL::display()
{
    node *t = start ;
    do
    {
        cout << t->data << " " ;
        t = t->next ;
    } while (t!=start);
    cout << endl ;
}
