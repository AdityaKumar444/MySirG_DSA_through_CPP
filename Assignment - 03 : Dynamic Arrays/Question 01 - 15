#include<bits/stdc++.h>
using namespace std ;
class DynArray
{
    private:
        int capacity , last_index , *ptr ;
    public:
        DynArray(){}
        DynArray(int n)
        {
            last_index = -1 ;
            capacity = n ;
            ptr = new int[capacity];
        }
        int getCapacity() { return capacity ; }
        void doubleArray();
        void halfArray();
        bool emptyOrNot();
        void append(int);
        void insert(int,int);
        void Delete(int);
        bool fullOrNot();
        int getElement(int);
        int countElements();
        int findElement(int);
        ~DynArray()
        {
            delete[]ptr;
        }
};
void DynArray::doubleArray()
{
    capacity = capacity * 2 ;
    int *p = new int[capacity] ;
    for(int i=0 ; i<=last_index ; i++)
    p[i] = ptr[i] ;
    delete[] ptr ;
    ptr = p ;
}
void DynArray::halfArray()
{
    capacity = capacity / 2 ;
    int *p = new int[capacity];
    for(int i=0 ; i<=last_index ; i++)
    p[i] = ptr[i] ;
    delete[] ptr ;
    ptr = p ;   
}
bool DynArray::emptyOrNot()
{
    if(last_index==-1)
    return true ;
    else
    return false ;
}
void DynArray::append(int element)
{
    if(last_index == capacity-1)
    doubleArray();
    last_index++;
    ptr[last_index] = element ;
}
void DynArray::insert(int index , int element)
{
    if(index<0 || index>last_index+1)
    cout << endl << "Invalid Index" << endl ;
    else  
    {
        if(last_index == capacity-1)
        doubleArray();
        for(int i=last_index ; i>=index ; i--)
        ptr[i+1] = ptr[i] ;
        ptr[index] = element ;
        last_index++;
    }
}
void DynArray::Delete(int index)
{
    if(last_index==-1)
    cout << "\nempty array\n" ;
    else if(index<0 || index>last_index)
    cout << endl << "Invalid Index" << endl ;
    else
    {
        int temp , x = capacity/2 ;
        for(int i=index ; i<last_index ; i++)
        {
            temp = ptr[i] ;
            ptr[i] = ptr[i+1] ;
            ptr[i+1] = temp ;
        }
        last_index = last_index - 1 ;
        if(x-1 >= last_index && capacity>1)
        halfArray();
    }
}
bool DynArray::fullOrNot()
{
    if(last_index==(capacity-1))
    return true ;
    else
    return false ;
}
int DynArray::getElement(int index)
{
    if(index>=0 && index<=last_index)
    return ptr[index];
    else
    return -1 ;
}
int DynArray::countElements()
{
    return (last_index+1) ;
}
int DynArray::findElement(int num)
{
    for(int i=0 ; i<=last_index ; i++)
    {
        if(ptr[i]==num)
        return i ;
    }
    return -1 ;
}
