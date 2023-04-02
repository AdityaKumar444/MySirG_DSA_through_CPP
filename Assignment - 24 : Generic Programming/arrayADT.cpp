#include<bits/stdc++.h>
using namespace std ;
template <typename type>
class Array
{
    private:
        int capacity , last_index=-1 ; 
        type *ptr ;
    public:
        bool emptyOrNot();
        bool fullOrNot();
        void append(type);
        type getElement(int);
        void Delete(int);
        void insert(int , type);
        int findElement(type);
        void display();
        int arraySize();
        int count();
        void edit(int , type);
        Array(){}
        Array(int n)
        {
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
        ~Array()
        {
            delete[]ptr;
        }
};
template <typename type>int Array<type>::count()
{
    return (last_index+1);
}
template <typename type>void Array<type>::edit(int index , type element)
{
    if(index>=0 && index<=last_index)
        ptr[index] = element ; 
}
template <typename type>int Array<type>::arraySize()
{
    return capacity ;
}
template <typename type>bool Array<type>::emptyOrNot()
{
    if(last_index==-1)
    return true ;
    else
    return false ;
}
template <typename type>bool Array<type>::fullOrNot()
{
    if(last_index==(capacity-1))
    return true ;
    else
    return false ;
}
template <typename type>void Array<type>::append(type element)
{
    if(last_index==capacity-1)
    cout << "no space available" << endl;
    else
    {
        last_index++;
        ptr[last_index] = element ;
    }
}
template <typename type>void Array<type>::display()
{
    for(int i=0 ; i<=last_index ; i++)
    cout << ptr[i] << " " ;
    cout << endl ;
}
template <typename type>type Array<type>::getElement(int index)
{
    if(index>=0 && index<=last_index)
        return ptr[index];
    return -1 ;
}
template <typename type>int Array<type>::findElement(type num)
{
    for(int i=0 ; i<=last_index ; i++)
    {
        if(ptr[i]==num)
        return i ;
    }
    return -1 ;
}
template <typename type>void Array<type>::insert(int index , type element)
{
    if(last_index==capacity-1)
        cout << "no space available" << endl;
    else if(index<0 || index>last_index+1)
        cout << "invalid index\n" ;
    else
    {
        for(int i=last_index ; i>=index ; i--)
            ptr[i+1] = ptr[i] ;   
        ptr[index] = element ; 
        last_index++;
    }
}
template <typename type>void Array<type>::Delete(int index)
{
    if(last_index==-1)
    cout << "empty array\n" ;
    else if(index<0 || index>last_index)
    cout << "invalid index\n" ;
    else
    {
        for(int i=index ; i<last_index ; i++)
        ptr[i] = ptr[i+1] ;
        last_index = last_index - 1 ;
    }
}