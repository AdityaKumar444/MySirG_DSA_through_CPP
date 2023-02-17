#include<bits/stdc++.h>
using namespace std ;
class Array
{
    private:
        int capacity , last_index=-1 , *ptr ;
    public:
        void reverse();
        bool emptyOrNot();
        bool fullOrNot();
        void append(int);
        int getElement(int);
        void del(int);
        void insert(int , int);
        int findElement(int);
        void display();
        int arraySize();
        int count();
        Array(){}
        Array(int n)
        {
            capacity = n ;
            ptr = new int[capacity];
        }
        void edit(int index , int element)
        {
            if(index>=0 && index<=last_index)
            ptr[index] = element ; 
        }
        ~Array()
        {
            delete[]ptr;
        }
};
int Array::count()
{
    return (last_index+1);
}
int Array::arraySize()
{
    return capacity ;
}
void Array::reverse()
{
    bool x = emptyOrNot() ;
    if(x==true)
    cout << "\nEmpty Array\n" ;
    else 
    {
        int *p = new int[capacity] , j = 0 ;
        for(int i=last_index ; i>=0 ; i--)
        {
            p[j] = ptr[i] ;
            j++ ;
        }
        delete[] ptr ;
        ptr = p ;
    }
}
bool Array::emptyOrNot()
{
    if(last_index==-1)
    return true ;
    else
    return false ;
}
bool Array::fullOrNot()
{
    if(last_index==(capacity-1))
    return true ;
    else
    return false ;
}
void Array::append(int element)
{
    if(last_index==capacity-1)
    cout << "no space available" << endl;
    else
    {
        last_index++;
        ptr[last_index] = element ;
    }
}
void Array::display()
{
    for(int i=0 ; i<=last_index ; i++)
    cout << ptr[i] << " " ;
    cout << endl ;
}
int Array::getElement(int index)
{
    if(index>=0 && index<=last_index)
    return ptr[index];
    else
    return -1 ;
}
int Array::findElement(int num)
{
    for(int i=0 ; i<=last_index ; i++)
    {
        if(ptr[i]==num)
        return i ;
    }
    return -1 ;
}
void Array::insert(int index , int element)
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
void Array::del(int index)
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
