#include<bits/stdc++.h>
using namespace std ; 
struct node
{
    int data ;
    node *prev , *next ;
};
class Deque
{
    private:
        node *front , *rear ;
    public:
        Deque() { front = rear = NULL ;}
        void insertFront(int);
        void insertRear(int);
        void deleteFront();
        void deleteRear();
        node *getFront();
        node *getRear();
        int Front();
        int Rear();
        bool isEmpty();
        ~Deque()
        {
            while(!isEmpty())
                deleteFront();
        }
};
bool Deque::isEmpty()
{
    if(front==NULL && rear==NULL)
        return true ;
    return false ;
}
void Deque::insertFront(int value)
{
    node *x = new node ;
    x->data = value ;
    x->prev = NULL ;
    x->next = front ;
    if(!isEmpty())
        front->prev = x ;
    else
        rear = x ;
    front = x ;
}
void Deque::insertRear(int value)
{
    node *x = new node ;
    x->data = value ;
    x->next = NULL ;
    x->prev = rear ;
    if(!isEmpty())
        rear->next = x ;
    else    
        front = x ;
    rear = x ;   
}
void Deque::deleteFront()
{
    if(!isEmpty())
    {
        node *temp = front ;
        if(front==rear)
            front = rear = NULL ;
        else
        {
            front = front->next ;
            front->prev = NULL ;
        }
        delete temp ;
    }
}
void Deque::deleteRear()
{
    if(!isEmpty())
    {
        node *temp = rear ;
        if(front==rear)
            front = rear = NULL ;
        else
        {
            rear = rear->prev ;
            rear->next = NULL ;
        }
        delete temp ;
    }
}
node * Deque::getFront()
{
    return front ;
}
node * Deque::getRear()
{
    return rear ;
}
int Deque::Front()
{
    if(!isEmpty())
        return front->data ;
    return INT_MIN ;
}
int Deque::Rear()
{
    if(!isEmpty())
        return rear->data ;
    return INT_MIN ;
}
