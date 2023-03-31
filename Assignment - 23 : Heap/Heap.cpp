#include<bits/stdc++.h>
using namespace std ;
class Heap
{
    private:
        int capacity , last_index , *ptr ;
        void doubleArray();
        void halfArray();
        int heapify_insert(int,int);
        void Swap(int,int);
    public:
        Heap(){}
        Heap(int n)
        {
            last_index = -1 ;
            capacity = n ;
            ptr = new int[capacity];
        }
        Heap(Heap &);
        Heap & operator=(Heap &);
        int getCapacity() { return capacity ; }
        bool isEmpty();
        void insert(int);
        int Delete();
        int getMax();
        int size();
        bool findElement(int);
        ~Heap(){ delete[]ptr; }
};
Heap & Heap::operator=(Heap &h)
{
    last_index = h.last_index ;
    capacity - h.capacity ;
    if(ptr!=NULL)
        delete[] ptr ;
    ptr = new int[capacity] ;
    for(int i=0 ; i<=last_index ; i++)
        ptr[i] = h.ptr[i] ;
    return *this ;
}
Heap::Heap(Heap &h)
{
    last_index = h.last_index ;
    capacity = h.capacity ;
    ptr = new int[capacity] ;
    for(int i=0 ; i<=last_index ; i++)
        ptr[i] = h.ptr[i] ;
}
void Heap::Swap(int i, int j)
{
    int temp = ptr[i] ;
    ptr[i] = ptr[j] ;
    ptr[j] = temp ;
}
void Heap::doubleArray()
{
    capacity = capacity * 2 ;
    int *p = new int[capacity] ;
    for(int i=0 ; i<=last_index ; i++)
    p[i] = ptr[i] ;
    delete[] ptr ;
    ptr = p ;
}
void Heap::halfArray()
{
    capacity = capacity / 2 ;
    int *p = new int[capacity];
    for(int i=0 ; i<=last_index ; i++)
    p[i] = ptr[i] ;
    delete[] ptr ;
    ptr = p ;   
}
bool Heap::isEmpty()
{
    if(last_index==-1)
        return true ;
    return false ;
}
int Heap::heapify_insert(int index , int element)
{
    int curr_index , parent_index ;
    for(curr_index = index ; curr_index > 0 ; curr_index = parent_index)
    { 
        parent_index = (curr_index-1)/2 ;
        if(element >= ptr[parent_index])        // checking if inserting element is greater than its parent element
            ptr[curr_index] = ptr[parent_index] ;   // then assigning parent element in current index position
        else                                     // else if smaller than breaking out of loop
            break;
    }
    return curr_index ;
}
void Heap::insert(int element)
{
    if(last_index == capacity-1)
        doubleArray();
    last_index++;
    int index = heapify_insert(last_index,element);
    ptr[index] = element ;
}
int Heap::Delete()
{
    int value = INT_MIN ;
    if(!isEmpty())
    {
        int index = 0 , left , right ;
        if(size()<=2 && size()>0)       // handling condition for heap size smaller than two
        {
            if(size()==1)
                return ptr[0] ;
            else if(ptr[0] < ptr[1])
            {
                value = ptr[1] ;
                last_index--;
            }
        }
        else
        {
            value = ptr[0] ;                // assigning return value to max element
            ptr[index] = ptr[last_index] ;
            last_index--;
            while((index*2)+2 < size()) // iterating until last child's index smaller than heap size
            {
                left = (index * 2) + 1 ;
                right = (index * 2) + 2 ;
                if(ptr[left] >= ptr[right] && ptr[left] > ptr[index])  // check if left child is greater than right and left child is greater than root
                {
                    Swap(left,index);    // swapping left child with root
                    index = left ;       // updating current postion of smaller element
                }
                else if(ptr[left] < ptr[right] && ptr[right] > ptr[index]) // check if right child is greater than left and right child is greater than root
                {
                    Swap(right,index);    // swapping right child with root
                    index = right ;       // updating current postion of smaller element
                }
                else
                    break;
            }
            if((capacity/2 - 1) >= last_index && capacity > 1)  
                halfArray();
        }
    }
    return value ;
}
int Heap::getMax()
{
    if(!isEmpty())
        return ptr[0];
    return INT_MIN ;
}
int Heap::size()
{
    return (last_index+1) ;
}
bool Heap::findElement(int num)
{
    for(int i=0 ; i<=last_index ; i++)
    {
        if(ptr[i]==num)
        return true ;
    }
    return false ;
}