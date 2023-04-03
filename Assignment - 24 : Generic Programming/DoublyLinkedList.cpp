#include<bits/stdc++.h>
using namespace std ; 
template <typename type>
struct node
{
    node *prev ;
    type data ;
    node *next ;
};
template <typename type>
class DLL
{
    private:
        node<type> *start ;
    public:
        DLL() { start = NULL ; }
        void insertAtStart(type);
        void insertAtEnd(type);
        node<type> * search(type);
        void insertAfter(node<type> * , type);
        void deleteFirst();
        void deleteLast();
        void deleteSpecific(node<type> *) ;
        void display();
        ~DLL()
        {
            while(start!=NULL)
                deleteFirst();
        }
};
template <typename type> void DLL<type>::insertAtStart(type item)
{
    node<type> *x = new node<type> ;
    x->data = item ;
    x->next = start ;
    x->prev = NULL ;
    if(start!=NULL)
        start->prev = x ;
    start = x ;
}
template <typename type> void DLL<type>::insertAtEnd(type item)
{
    if(start==NULL)
        insertAtStart(item);
    else
    {
        node<type> *traverse ;
        traverse = start ;
        node<type> *x = new node<type> ;
        x->data = item ;
        x->next = NULL ;
        while(traverse->next!=NULL)
            traverse = traverse->next ;
        x->prev = traverse ;
        traverse->next = x ;
    }
}
template <typename type> node<type> * DLL<type>::search(type item)
{
    node<type> *traverse ;
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
template <typename type> void DLL<type>::insertAfter(node<type> * t , type item)
{
    if(t)
    {
        node<type> *x = new node<type> ;
        x->data = item ;
        x->next = t->next ;
        x->prev = t ;
        if(t->next!=NULL)
            t->next->prev = x ;
        t->next = x ;
    }
}
template <typename type> void DLL<type>::deleteFirst()
{
    if(start!=NULL)
    {
        node<type> * temp ;
        if(start->next!=NULL)
            start->next->prev = NULL ;
        temp = start->next ;
        delete start ;
        start = temp ;
    }
    else if(start==NULL)
        cout << "Empty List" << endl ;
}
template <typename type> void DLL<type>::deleteLast()
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
        node<type> *traverse ;
        traverse = start ;
        while(traverse->next->next!=NULL)
            traverse = traverse->next ;
        delete traverse->next ;
        traverse->next = NULL ;
    }
}
template <typename type> void DLL<type>::deleteSpecific(node<type> *temp)
{
    if(temp->prev)
        temp->prev->next = temp->next ;
    else 
        start = temp->next ;
    if(temp->next)
        temp->next->prev = temp->prev ;
    delete temp ;
}
template <typename type> void DLL<type>::display()
{
    node<type> *traverse ;
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