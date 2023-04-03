#include<bits/stdc++.h>
using namespace std ; 
template <typename type>
struct node
{
    type data ;
    node *prev , *next ;
};
template <typename type>
class Deque
{
    private:
        node<type> *front , *rear ;
    public:
        Deque() { front = rear = NULL ;}
        void insertFront(type);
        void insertRear(type);
        void deleteFront();
        void deleteRear();
        node<type> *getFront();
        node<type> *getRear();
        type Front();
        type Rear();
        bool isEmpty();
        ~Deque()
        {
            while(!isEmpty())
                deleteFront();
        }
};
template <typename type> bool Deque<type>::isEmpty()
{
    if(front==NULL && rear==NULL)
        return true ;
    return false ;
}
template <typename type> void Deque<type>::insertFront(type value)
{
    node<type> *x = new node<type> ;
    x->data = value ;
    x->prev = NULL ;
    x->next = front ;
    if(!isEmpty())
        front->prev = x ;
    else
        rear = x ;
    front = x ;
}
template <typename type> void Deque<type>::insertRear(type value)
{
    node<type> *x = new node<type> ;
    x->data = value ;
    x->next = NULL ;
    x->prev = rear ;
    if(!isEmpty())
        rear->next = x ;
    else    
        front = x ;
    rear = x ;   
}
template <typename type> void Deque<type>::deleteFront()
{
    if(!isEmpty())
    {
        node<type> *temp = front ;
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
template <typename type> void Deque<type>::deleteRear()
{
    if(!isEmpty())
    {
        node<type> *temp = rear ;
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
template <typename type> node<type> * Deque<type>::getFront()
{
    return front ;
}
template <typename type> node<type> * Deque<type>::getRear()
{
    return rear ;
}
template <typename type> type Deque<type>::Front()
{
    if(!isEmpty())
        return front->data ;
}
template <typename type> type Deque<type>::Rear()
{
    if(!isEmpty())
        return rear->data ;
}