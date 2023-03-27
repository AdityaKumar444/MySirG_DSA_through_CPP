#include<bits/stdc++.h>
using namespace std ;
int * selectionSort(int *,int); 
int * selectionSort(int *arr , int size)
{
    int min_index , temp ;
    for(int i=0 ; i<size-1 ; i++)
    {
        min_index = i ;
        for (int j=i+1 ; j<size ; j++)
        {
            if(arr[min_index] > arr[j])
                min_index = j ;
        }
        temp = arr[i] ;
        arr[i] = arr[min_index] ;
        arr[min_index] = temp ;
    }
    return arr ;
} 
int main () 
{
    int arr[8] = {10,5,6,3,2,20,100,80} ;
    selectionSort(arr,8);
    for(int i=0 ; i<8 ; i++)
        cout << arr[i] << " " ;
    return 0 ; 
}