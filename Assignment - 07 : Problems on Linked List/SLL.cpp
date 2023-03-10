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
        SLL(){ start = NULL ; }
        void insertAtStart(int);
        void insertAtLast(int);
        void insertAfter(int , node *);
        void deleteFirst();
        void deleteLast();
        void deleteSpecific(node*);
        void display();
        node * search(int);
        node *getStart() { return start ;}
        void setStart(node *x) { start = x ;}
        ~SLL()
        {
            while(start!=NULL)
            {
                deleteFirst();
            }
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
void SLL::deleteSpecific(node *t)
{
    node *traverse ;
    traverse = start ;
    if(start==NULL)
    cout << "Empty list" << endl ; 
    else if(start==t)
    {
        start = t->next ;
        delete t ;
    }
    else
    {
        while(traverse->next!=t)
        {
            traverse = traverse->next ;
        }
        traverse->next = t->next ;
        delete t ;
    }
}
void SLL::deleteLast()
{
    node *traverse ;
    traverse = start ;
    if(start==NULL)
    cout << "\nEmpty list\n" ;
    else if(start->next==NULL)
    {
        delete start ;
        start = NULL ;
    }
    else
    {
        while(traverse->next->next!=NULL)
        { traverse = traverse->next ; }
        delete traverse->next ;
        traverse->next = NULL ;
    }
}
void SLL::deleteFirst()
{
    if(start!=NULL)
    {
        node *temp = start->next ;
        delete start ;
        start = temp ;
    }
}
void SLL::insertAfter(int item , node *t)
{
    node * x = new node ;
    x->data = item ;
    x->next = t->next ;
    t->next = x ;
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
void SLL::insertAtStart(int item)
{
    node *x = new node ;
    x->data = item ;
    x->next = start ;
    start = x ;
}
void SLL::insertAtLast(int item)
{
    node * temp ;
    node *x = new node ;
    x->data = item ;
    x->next = NULL ;
    if(start==NULL)
    start = x ;
    else
    {
        temp = start ;
        while(temp->next!=NULL)
        temp = temp->next ;
        temp->next = x ;
    }
}
