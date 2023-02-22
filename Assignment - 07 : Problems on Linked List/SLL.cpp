#include<bits/stdc++.h>
using namespace std ;
class node
{
    public:
        int data ;
        node *next ;
};
class SLL 
{
    private:
        node *start ;
    public:
        SLL()
        {
            start = NULL ;
        }
        void insertAtStart(int);
        void insertAtLast(int);
        void insertAfterSpecified(int , node *);
        void deleteFirst();
        void deleteLast();
        void deleteSpecific(node*);
        void display();
        node * search(int);
        node * getStart() { return start ; }
        ~SLL()
        {
            while(start!=NULL)
               deleteFirst();
        }
};
void SLL::display()
{
    node *traverse ;
    traverse = start ;
    while(traverse!=NULL)
    {
        cout << traverse->data << " " ;
        traverse = traverse->next ;
    }
    cout << endl ;
}
void SLL::insertAtStart(int item)
{
    node *x = new node ;
    x->data = item ;
    x->next = start ;
    start = x ;
}
void SLL::insertAtLast(int item)
{
    node *x = new node ;
    node * traverse ;
    x->data = item ;
    x->next = NULL ;
    if(start==NULL)
    start = x ;
    else
    {
        traverse = start ;
        while(traverse->next!=NULL)
        {
            traverse = traverse->next ;
        }
        traverse->next = x ;
    }
}
void SLL::insertAfterSpecified(int item , node *t)
{
    node *x = new node ;
    x->data = item ;
    x->next = t->next ;
    t->next = x ;
}
void SLL::deleteFirst()
{
    node * temp ;
    if(start!=NULL)
    {
        temp = start->next ;
        delete start ;
        start = temp ;
    }
}
void SLL::deleteLast()
{
    node *traverse ;
    if(start->next==NULL)
    {
        delete start ;
        start = NULL ;
    }
    else if(start!=NULL)
    {
        traverse = start ;
        while(traverse->next->next!=NULL)
        {
            traverse = traverse->next ;
        }
        delete traverse->next ;
        traverse->next = NULL ;
    }
}
void SLL::deleteSpecific(node *t)
{
    node *traverse ;
    if(start==t)
    {
        start = t->next ;
        delete t ;
    }
    else if(start!=NULL)
    {
        traverse = start ;
        while(traverse->next!=t)
        {
            traverse = traverse->next ;
        }
        traverse->next = t->next ;
        delete t ;
    }
}
node * SLL::search(int item)
{
    node *traverse ;
    traverse = start ;
    while(traverse!=NULL)
    {
        if(traverse->data==item)
        return traverse ;
        traverse = traverse->next ;
    }
    return traverse ;
}
