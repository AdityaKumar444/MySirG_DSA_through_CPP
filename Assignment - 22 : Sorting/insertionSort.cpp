#include<bits/stdc++.h>
using namespace std ;
int * insertionSort(int *,int); 
int * insertionSort(int *arr , int size)
{
    int temp , index ;                  // initializing temp variable and index to contain index of temp 
    for(int i=0 ; i<size ; i++)         // iterating till the end of array 
    {
        temp = arr[i] ;                 // assigning the current value in temp
        index = i ;                     // assigning current value's index
        for (int j=i-1 ; j>=0 ; j--)    // iterating backwards to compare temp with previous values
        {
            if(temp < arr[j])           // if temp is smaller than previous value , then swapping it with
            {                           // previous value and updating temp variable index to current position 
                arr[index] = arr[j] ;   // of temp variable
                arr[j] = temp ;
                index = j ; 
            }
            else if(temp > arr[j])      // if temp is greater than previous value then breaking inner loop 
                break;
        }
    }
    return arr ;                        // returning the sorted array
} 
int main () 
{
    int arr[10] = {50 , 20 , 37 , 91 , 64 , 18 , 43 , 59 , 72 , 81};
    insertionSort(arr,10);
    for(int i=0 ; i<10 ; i++)
        cout << arr[i] << " " ;
    return 0 ; 
}