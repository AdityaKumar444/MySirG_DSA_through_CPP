#include<bits/stdc++.h>
using namespace std ;
template <typename type>
struct node
{
    type data ;
    node *next ;
};
template <typename type>
class Stack
{
    private:
        node<type> *top ;
    public:
        Stack() { top = NULL ;}
        void push(type);
        type peek();
        void pop();
        bool isEmpty();
        void reverse();
        ~Stack()
        {
            while(top)
                pop();
        }
};
template <typename type> void Stack<type>::push(type item)
{
    node<type> *x = new node<type> ;
    x->data = item ;
    x->next = top ;
    top = x ;
}
template <typename type> type Stack<type>::peek()
{
    if(top)
        return top->data ;
}
template <typename type> void Stack<type>::pop()
{
    if(top)
    {
        node<type> *temp = top ;
        top = top->next ;
        delete temp ;   
    }
}
template <typename type> bool Stack<type>::isEmpty()
{
    if(top==NULL)
        return true ;
    return false ;
}
template <typename type> void Stack<type>::reverse()
{
    node<type> *t1 , *t2 , *t3 ;
    if(top->next!=NULL)
    {
        t1 = top ;
        t2 = t1->next ;
        t3 = t2->next ;
        t1->next = NULL ;
        do
        {
            t2->next = t1 ;
            t1 = t2 ;
            t2 = t3 ;
            if(t3!=NULL)
                t3 = t3->next ;
        }while(t2!=NULL);
        top = t1 ;
    }
}