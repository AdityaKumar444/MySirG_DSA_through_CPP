#include<bits/stdc++.h>
using namespace std ;
int * BubbleSort(int *,int); 
int * BubbleSort(int *arr , int size)
{
    int temp ;
    for(int i=1 ; i<=size-1 ; i++)
    {
        for (int j=0 ; j<size-1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j] ;
                arr[j] = arr[j+1] ;
                arr[j+1] = temp ;
            }   
        }
    }
    return arr ;
} 
int main () 
{
    int arr[8] = {10, 5, 6, 3, 2, 20, 100, 80};
    BubbleSort(arr,8);
    for(int i=0 ; i<8 ; i++)
        cout << arr[i] << " " ;
    return 0 ; 
}