#include<bits/stdc++.h>
using namespace std ;
template<typename type>
class node
{
    public:
        type data ;
        node *next ;
};
template<typename type>
class SLL 
{
    private:
        node<type> *start ;
    public:
        SLL(){ start = NULL ; }
        void insertAtStart(type);
        void insertAtLast(type);
        void insertAfter(type , node<type> *);
        void deleteFirst();
        void deleteLast();
        void deleteSpecific(node<type>*);
        void display();
        node<type> * search(type);
        node<type> *getStart() { return start ;}
        void setStart(node<type> *x) { start = x ;}
        ~SLL()
        {
            while(start!=NULL)
                deleteFirst();
        }
};
template<typename type>void SLL<type>::display()
{
    node<type> *traverse ;
    traverse = start ;
    while(traverse!=NULL)
    {
        cout << traverse->data << " " ;
        traverse = traverse->next ;
    }
    cout << endl ;
}
template<typename type>void SLL<type>::deleteSpecific(node<type> *t)
{
    node<type> *traverse ;
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
            traverse = traverse->next ;
        traverse->next = t->next ;
        delete t ;
    }
}
template<typename type>void SLL<type>::deleteLast()
{
    node<type> *traverse ;
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
            traverse = traverse->next ;
        delete traverse->next ;
        traverse->next = NULL ;
    }
}
template<typename type>void SLL<type>::deleteFirst()
{
    if(start!=NULL)
    {
        node<type> *temp = start->next ;
        delete start ;
        start = temp ;
    }
}
template<typename type>void SLL<type>::insertAfter(type item , node<type> *t)
{
    node<type> * x = new node<type> ;
    x->data = item ;
    x->next = t->next ;
    t->next = x ;
}
template<typename type>node<type> * SLL<type>::search(type item)
{
    node<type> *traverse ;
    traverse = start ;
    while(traverse!=NULL)
    {
        if(traverse->data==item)
            return traverse ;
        traverse = traverse->next ;
    }
    return traverse ;
}
template<typename type>void SLL<type>::insertAtStart(type item)
{
    node<type> *x = new node<type> ;
    x->data = item ;
    x->next = start ;
    start = x ;
}
template<typename type>void SLL<type>::insertAtLast(type item)
{
    node<type> * temp ;
    node<type> *x = new node<type> ;
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