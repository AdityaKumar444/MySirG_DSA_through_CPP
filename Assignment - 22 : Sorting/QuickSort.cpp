#include<bits/stdc++.h>
using namespace std ;
void Swap(int *,int,int);
int partition(int *,int,int);
void QuickSort(int *,int,int); 
void QuickSort(int *arr , int low , int high)       
{
    if(low < high)
    {
        int pivot = partition(arr,low,high);        // getting pivot element index
        QuickSort(arr, low, pivot-1);               // passing left subarray to pivot for sorting
        QuickSort(arr, pivot+1, high);              // passing right subarray to pivot for sorting
    }
    return;
} 
int partition(int *arr , int low , int high)        // partition function to fix the pivot in its right position 
{
    int forw , back ;                               // forw and back are two pointers moving forward and backward
    forw = low ;
    back = high ;
    int pivot = arr[forw] ;                         // taking pivot as first element
    while(forw < back)                              // iterating until first pointer crosses second pointer
    {
        while(arr[forw] <= pivot)                   // iterating until first pointer element is smaller than pivot
            forw++;
        while(arr[back] > pivot)                    // iterating until second pointer element is greater than pivot
            back--;
        if(forw < back)                             // if first pointer's position is less than second, then swapping the
            Swap(arr,forw,back);                    // elements to arrange them in a fashion such that elements smaller than
    }                                               // pivot will be on left and greater will be on right
    Swap(arr,low,back);                             // Now swapping the pivot with second pointer to fix it's right position
    return back ;
}
void Swap(int *arr , int i , int j)                 // swap function to swap elememts at given indexes
{
    int temp ;
    temp = arr[i] ;
    arr[i] = arr[j] ;
    arr[j] = temp ;
}
int main () 
{
    int arr[9] = {58 , 62 , 91 , 43 , 29 , 37 , 88 , 72 , 16};
    QuickSort(arr,0,8);
    for(int i=0 ; i<9 ; i++)
        cout << arr[i] << " " ;
    return 0 ; 
}
