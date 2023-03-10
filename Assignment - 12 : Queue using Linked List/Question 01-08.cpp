#include<bits/stdc++.h>
using namespace std ;
struct node
{
    int data ;
    node * next ;
};
class Queue
{
    private:
        node *front , *rear ;
    public:
        Queue(){ front = rear = NULL ; }
        void enqueue(int);
        int Rear();
        node * getRear();
        int Front();
        node * getFront();
        void dequeue();
        int size();
        bool isEmpty();
        ~Queue()
        {
            while(!isEmpty())
                dequeue();
        }
};
void Queue::enqueue(int value)
{
    node *x = new node ;
    x->data = value ;
    x->next = NULL ;
    if(isEmpty())
        front = rear = x ;
    rear = rear->next = x ;
}
int Queue::Rear()
{
    if(!isEmpty())
        return rear->data ;
    return INT_MIN ;
}
node * Queue::getRear()
{
    return rear ;
}
int Queue::Front()
{
    if(!isEmpty())
        return front->data ;
    return INT_MIN ;
}
node * Queue::getFront()
{
    return front ;
}
void Queue::dequeue()
{
    if(!isEmpty())
    {
        node *temp = front ;
        front = front->next ;
        if(front==NULL)
            rear = NULL ;
        delete temp ;
    }
}
int Queue::size()
{
    int count = 0 ;
    if(!isEmpty())
    {
        node *t = front ;
        while(t!=NULL)
        {
            count++;
            t = t->next ;
        }
    }
    return count ;
}
bool Queue::isEmpty()
{
    if(front==NULL && rear==NULL)
        return true ;
    return false ;
}
