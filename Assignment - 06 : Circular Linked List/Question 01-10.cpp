#include<bits/stdc++.h>
using namespace std ; 
struct node
{
    int data ;
    node *next ;
};
class CLL
{
    private:
        node *last ;
    public:
        CLL() { last = NULL ; }
        void insertAtStart(int);
        void insertAtEnd(int);
        node * search(int);
        void insertAfter(node *,int);
        void deleteFirst();
        void deleteLast();
        void deleteSpecific(node *);
        ~CLL() 
        {
            while(last!=NULL)
            deleteFirst();
        }
};
void CLL::insertAtStart(int item)
{
    node *x = new node ;
    x->data = item ;
    if(last!=NULL)
    {
        x->next = last->next ;
        last->next = x ;
    }
    else
    { 
        x->next = x ;
        last = x ;
    }
}
void CLL::insertAtEnd(int item)
{
    node *x = new node ;
    x->data = item ;
    if(last!=NULL)
    {
        x->next = last->next ;
        last->next = x ;
        last = x ;
    }
    else
    {
        x->next = x ;
        last = x ;
    }
}
node * CLL::search(int item)
{
    node *traverse ;
    if(last!=NULL)
    {
        traverse = last->next ;
        do
        {
            if(traverse->data==item)
                return traverse ;
            traverse = traverse->next ;

        }while(traverse!=last->next );
    }
    return NULL ;
}
void CLL::insertAfter(node * t , int item)
{
    if(last!=NULL)
    {
        node *x = new node ;
        x->data = item ;
        x->next = t->next ;
        t->next = x ;
        if(t==last)
            last = x ;
    }
}
void CLL::deleteFirst()
{
    if(last!=NULL)
    {
        node *temp = last->next ;
        if(last==last->next)
            last = NULL ;
        else
            last->next = temp->next ;
        delete temp ;
    }  
}
void CLL::deleteLast()
{
    if(last!=NULL)
    {
        node *temp = last->next ;
        while(temp->next!=last)
            temp = temp->next ;
        if (temp==last)
        {
            delete last ;
            last = NULL ;
        }
        else
        {
            temp->next = last->next ;
            delete last ;
            last = temp ;
        }
    }
}
void CLL::deleteSpecific(node *temp)
{
    if(last!=NULL)
    {
        node *t = last->next ;
        while(t->next!=temp)
            t = t->next ;
        t->next = temp->next ;
        if(t==temp)
            last = NULL ;
        else if(temp==last)
            last = t ;
        delete temp ;
    }
}
