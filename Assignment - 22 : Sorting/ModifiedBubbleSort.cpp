#include<bits/stdc++.h>
using namespace std ;
int * ModifiedBubbleSort(int *,int); 
int * ModifiedBubbleSort(int *arr , int size)
{
    int temp ;
    bool flag ;
    for(int i=1 ; i<=size-1 ; i++)
    {
        flag = false ;
        for (int j=0 ; j<size-1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j] ;
                arr[j] = arr[j+1] ;
                arr[j+1] = temp ;
                flag = true ;
            }
        }
        if(flag==false)
            break;
    }
    return arr ;
} 
int main () 
{
    int arr[5] = {31 , 42 , 18 , 60 , 90};
    ModifiedBubbleSort(arr,5);
    for(int i=0 ; i<5 ; i++)
        cout << arr[i] << " " ;
    return 0 ; 
}