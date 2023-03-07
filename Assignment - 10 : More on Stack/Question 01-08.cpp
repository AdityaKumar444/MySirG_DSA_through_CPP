#include<bits/stdc++.h>
using namespace std ;
struct node
{
    int data ;
    node *next ;
};
class Stack
{
    private:
        node *top ;
    public:
        Stack() { top = NULL ;}
        void push(int);
        int peek();
        void pop();
        bool isEmpty();
        void reverse();
        ~Stack()
        {
            while(top)
                pop();
        }
};
void Stack::push(int item)
{
    node *x = new node ;
    x->data = item ;
    x->next = top ;
    top = x ;
}
int Stack::peek()
{
    if(top)
        return top->data ;
    return INT_MIN ;
}
void Stack::pop()
{
    if(top)
    {
        node *temp = top ;
        top = top->next ;
        delete temp ;   
    }
}
bool Stack::isEmpty()
{
    if(top==NULL)
        return true ;
    return false ;
}
void Stack::reverse()
{
    node *t1 , *t2 , *t3 ;
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
int len(int x)
{
    int count=0;
    while(x)
    {
        x/=10;
        count++;
    }
    return count;
}
bool isPalindrome(int x)
{
    Stack s;
    int l=len(x);
    int i=l/2;
    while(i)
    {
        s.push(x%10);
        x/=10;
        i--;
    }
    if(l%2)
    {
        x/=10;
        while(x)
        {
            if(x%10==s.peek())
            {
                s.pop();
                x/=10;
            }
            else
                return false;
        }
    }
    else
    {
        while(x)
        {
            if(x%10==s.peek())
            {
                s.pop();
                x/=10;
            }
            else
                return false;
        }   
    }
    return true;
}
