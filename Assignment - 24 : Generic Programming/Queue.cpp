#include<bits/stdc++.h>
using namespace std ;
template <typename type>
struct node
{
    type data ;
    node * next ;
};
template <typename type>
class Queue
{
    private:
        node<type> *front , *rear ;
    public:
        Queue(){ front = rear = NULL ; }
        void enqueue(type);
        type Rear();
        node<type> * getRear();
        type Front();
        node<type> * getFront();
        void dequeue();
        int size();
        bool isEmpty();
        ~Queue()
        {
            while(!isEmpty())
                dequeue();
        }
};
template <typename type> void Queue<type>::enqueue(type value)
{
    node<type> *x = new node<type> ;
    x->data = value ;
    x->next = NULL ;
    if(isEmpty())
        front = rear = x ;
    rear = rear->next = x ;
}
template <typename type> type Queue<type>::Rear()
{
    if(!isEmpty())
        return rear->data ;
}
template <typename type> node<type> * Queue<type>::getRear()
{
    return rear ;
}
template <typename type> type Queue<type>::Front()
{
    if(!isEmpty())
        return front->data ;
}
template <typename type> node<type> * Queue<type>::getFront()
{
    return front ;
}
template <typename type> void Queue<type>::dequeue()
{
    if(!isEmpty())
    {
        node<type> *temp = front ;
        front = front->next ;
        if(front==NULL)
            rear = NULL ;
        delete temp ;
    }
}
template <typename type> int Queue<type>::size()
{
    int count = 0 ;
    if(!isEmpty())
    {
        node<type> *t = front ;
        while(t!=NULL)
        {
            count++;
            t = t->next ;
        }
    }
    return count ;
}
template <typename type> bool Queue<type>::isEmpty()
{
    if(front==NULL && rear==NULL)
        return true ;
    return false ;
}