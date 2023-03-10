#include<bits/stdc++.h>
using namespace std ;
class Queue
{
    private:
        int capacity ;
        int front , rear ;
        int *ptr ;
    public:
        Queue(int cap)
        {
            front = -1 ;
            rear = -1 ;
            capacity = cap ;
            ptr = new int[capacity];
        }
        Queue(Queue &);
        Queue & operator=(Queue &);
        void enqueue(int);
        void dequeue();
        bool isEmpty();
        bool isFull();
        int Rear();
        int Front();
        int size();
        ~Queue(){ delete[] ptr ; }
};
Queue::Queue(Queue &q)
{
    front = q.front ;
    rear = q.rear ;
    capacity = q.capacity ;
    ptr = new int[capacity];
    int count = q.size() , i = q.front ;
    while(count)
    {
        ptr[i] = q.ptr[i] ;
        if(i==capacity-1)
            i = 0 ;
        else
            i++;
        count--;
    }
}
Queue & Queue::operator=(Queue &q)
{
    front = q.front ;
    rear = q.rear ;
    capacity = q.capacity ;
    if(ptr!=NULL)
        delete[] ptr ;
    ptr = new int[capacity];
    int count = q.size() , i = q.front ;
    while(count)
    {
        ptr[i] = q.ptr[i] ;
        if(i==capacity-1)
            i = 0 ;
        else
            i++;
        count--;
    }
    return *this ;
}
void Queue::enqueue(int data)
{
    if(isFull())
        cout << "Queue Full" << endl ;
    else
    {
        if(isEmpty())
        {
            front++ , rear++;
            ptr[rear] = data ;
        }
        else if(rear==capacity-1)
        {
            rear = 0 ;
            ptr[rear] = data ;
        }
        else
        {
            rear++;
            ptr[rear] = data ;
        } 
    }
}
void Queue::dequeue()
{
    if(isEmpty())
        cout << "Empty Queue" << endl ;
    else if(front==rear)
        front = rear = -1 ;
    else if(front==capacity-1)
        front = 0 ;
    else
        front++;
}
bool Queue::isEmpty()
{
    if(front==-1 && rear==-1)
        return true ;
    return false ;
}
bool Queue::isFull()
{
    if((front==0 && rear==capacity-1) || rear+1==front)
        return true ;
    return false ;   
}
int Queue::Rear()
{
    if(!isEmpty())
        return ptr[rear];
    return INT_MIN ;
}
int Queue::Front()
{
    if(!isEmpty())
        return ptr[front];
    return INT_MIN ;
}
int Queue::size()
{
    int count = 0 ;
    if(isEmpty())
        return 0 ;
    else if(front <= rear)
        count = rear - front + 1 ;
    else if(front > rear)
        count = capacity - front + rear + 1 ;
    return count ;
}
