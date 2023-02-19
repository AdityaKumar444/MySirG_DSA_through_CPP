#include<bits/stdc++.h>
using namespace std ; 
struct node
{
    node *prev ;
    int data ;
    node *next ;
};
class DLL
{
    private:
        node *start ;
    public:
        DLL()
        {
            start = NULL ;
        }
        void insertAtStart(int);
        void insertAtEnd(int);
        node * search(int);
        void insertAfter(node * , int);
        void deleteFirst();
        void deleteLast();
        void deleteSpecific(node *) ;
        void display();
        ~DLL()
        {
            while(start!=NULL)
            deleteFirst();
        }
};
void DLL::insertAtStart(int item)
{
    node *x = new node ;
    x->data = item ;
    x->next = start ;
    x->prev = NULL ;
    if(start!=NULL)
    start->prev = x ;
    start = x ;
}
void DLL::insertAtEnd(int item)
{
    if(start==NULL)
    insertAtStart(item);
    else
    {
        node *traverse ;
        traverse = start ;
        node *x = new node ;
        x->data = item ;
        x->next = NULL ;
        while(traverse->next!=NULL)
        traverse = traverse->next ;
        x->prev = traverse ;
        traverse->next = x ;
    }
}
node * DLL::search(int item)
{
    node *traverse ;
    traverse = start ;
    if(start!=NULL)
    {
        while(traverse!=NULL)
        {
            if(traverse->data==item)
            return traverse ;
            traverse = traverse->next ;
        }
    }
    return traverse ;
}
void DLL::insertAfter(node * t , int item)
{
    if(t)
    {
        node *x = new node ;
        x->data = item ;
        x->next = t->next ;
        x->prev = t ;
        if(t->next!=NULL)
        t->next->prev = x ;
        t->next = x ;
    }
}
void DLL::deleteFirst()
{
    if(start!=NULL)
    {
        node * temp ;
        if(start->next!=NULL)
        start->next->prev = NULL ;
        temp = start->next ;
        delete start ;
        start = temp ;
    }
    else if(start==NULL)
    cout << "Empty List" << endl ;
}
void DLL::deleteLast()
{
    if(start==NULL)
    cout << "Empty List" << endl ;
    else if(start->next==NULL)
    {
        delete start ;
        start = NULL ;
    }
    else
    {
        node *traverse ;
        traverse = start ;
        while(traverse->next->next!=NULL)
        traverse = traverse->next ;
        delete traverse->next ;
        traverse->next = NULL ;
    }
}
void DLL::deleteSpecific(node *temp)
{
    if(temp->prev)
        temp->prev->next = temp->next ;
    else 
        start = temp->next ;
    if(temp->next)
        temp->next->prev = temp->prev ;
    delete temp ;
}
void DLL::display()
{
    node *traverse ;
    traverse = start ;
    if(traverse==NULL)
    cout << "Empty list" << endl ;
    else
    {
        while(traverse!=NULL)
        {
            cout << traverse->data << " " ;
            traverse = traverse->next ;
        }
        cout << endl ;
    }
}
