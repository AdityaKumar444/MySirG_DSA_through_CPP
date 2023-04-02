#include<bits/stdc++.h>
using namespace std ;
template<typename type>
class DynArray
{
    private:
        int capacity , last_index ;
        type *ptr ;
    public:
        DynArray(){}
        DynArray(int n)
        {
            last_index = -1 ;
            capacity = n ;
            ptr = new type[capacity];
        }
        Array(const Array &a)
        {
            capacity = a.capacity ;
            last_index = a.last_index ;
            ptr = new type[capacity];
            for(int i=0 ; i<=last_index ; i++)
                ptr[i] = a.ptr[i] ;
        }
        void operator=(Array &arr)
        {
            capacity = arr.capacity ;
            last_index = arr.last_index ;
            if(ptr!=NULL)
                delete[] ptr ;
            ptr = new type[capacity];
            for(int i=0 ; i<=last_index ; i++)
                ptr[i] = arr.ptr[i] ;
        }
        int getCapacity() { return capacity ; }
        void doubleArray();
        void halfArray();
        bool emptyOrNot();
        void append(type);
        void insert(int,type);
        void Delete(int);
        bool fullOrNot();
        type getElement(int);
        int countElements();
        int findElement(int);
        ~DynArray() { delete[]ptr; }
};
template<typename type> void DynArray<type>::doubleArray()
{
    capacity = capacity * 2 ;
    type *p = new type[capacity] ;
    for(int i=0 ; i<=last_index ; i++)
        p[i] = ptr[i] ;
    delete[] ptr ;
    ptr = p ;
}
template<typename type> void DynArray<type>::halfArray()
{
    capacity = capacity / 2 ;
    type *p = new type[capacity];
    for(int i=0 ; i<=last_index ; i++)
        p[i] = ptr[i] ;
    delete[] ptr ;
    ptr = p ;   
}
template<typename type> bool DynArray<type>::emptyOrNot()
{
    if(last_index==-1)
        return true ;
    return false ;
}
template<typename type> void DynArray<type>::append(type element)
{
    if(last_index == capacity-1)
        doubleArray();
    last_index++;
    ptr[last_index] = element ;
}
template<typename type> void DynArray<type>::insert(int index , type element)
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
template<typename type> void DynArray<type>::Delete(int index)
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
template<typename type> bool DynArray<type>::fullOrNot()
{
    if(last_index==(capacity-1))
        return true ;
    return false ;
}
template<typename type> type DynArray<type>::getElement(int index)
{
    if(index>=0 && index<=last_index)
        return ptr[index];
    return -1 ;
}
template<typename type> int DynArray<type>::countElements()
{
    return (last_index+1) ;
}
template<typename type> int DynArray<type>::findElement(int num)
{
    for(int i=0 ; i<=last_index ; i++)
    {
        if(ptr[i]==num)
            return i ;
    }
    return -1 ;
}