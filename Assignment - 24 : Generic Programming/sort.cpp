#include<bits/stdc++.h>
using namespace std ;
template <typename x>
void mergeSorted(x *,int,int,int);                         // merge function to merge two sorted arrays
template <typename x>
void MergeSort(x *, int , int);                               // MergeSort method to sort elements
template <typename x>
void MergeSort(x *arr, int start, int end)
{
    if(start < end)                                        // base case, if start pointer is less than end pointer the only further execution of code
    {
        int mid = (start + end) / 2 ;                       // getting middle index
        MergeSort(arr,start,mid);                           // calling MergeSort for left sub-array
        MergeSort(arr,mid+1,end);                           // calling MergeSort for right sub-array
        mergeSorted(arr,start,mid,end);                     // merging two sorted sub-arrays
    }
}
template <typename x>
void mergeSorted(x *arr, int start, int mid, int end)
{
    int len1 = mid - start + 1 ;                            // finding length of first sub-array
    int len2 = end - mid ;                                  // finding length of second sub-array
    x *arr1 = new x[len1];                              // dynamically created first sub-array temporarily
    x *arr2 = new x[len2];                              // dynamically created second sub-array temporarily
    int mainIndex = start ;                                // initializing main index to start for main array for copying elements into sub-array
    for(int i=0 ; i<len1 ; i++)
    {
        arr1[i] = arr[mainIndex] ;                          // copying elements from main array to first sub-array
        mainIndex++;
    }
    mainIndex = mid + 1 ;                                   // initializing main index to mid+1 for main array for copying elements into sub-array
    for(int i=0 ; i<len2 ; i++)
    {
        arr2[i] = arr[mainIndex] ;                          // copying elements from main array to second sub-array
        mainIndex++;
    }
    int index1 = 0 ;                                        // initializing first index for first sub-array
    int index2 = 0 ;                                        // initializing second index for second sub-array
    mainIndex = start ;                                     // initializing main index to start to sort elements and put them in main array
    while(index1 < len1 && index2 < len2)                   // iterate until either sub-array gets completed iteration
    {
        if(arr1[index1] < arr2[index2])                     // if element of first sub-array is smaller than second then put them in main arrray
        {
            arr[mainIndex] = arr1[index1] ;
            index1++;
        }
        else                                                // if element of second sub-array is smaller than first then put them in main arrray
        {
            arr[mainIndex] = arr2[index2] ;
            index2++;
        }
        mainIndex++;                                        // increment main index 
    }
    while(index1 < len1)                                    // if second sub-array gets completed then copy elements of first sub-array into main array
    {
        arr[mainIndex] = arr1[index1];
        mainIndex++;
        index1++;
    }
    while(index2 < len2)                                    // if first sub-array gets completed then copy elements of second sub-array into main array
    {
        arr[mainIndex] = arr2[index2];
        mainIndex++;
        index2++;
    }
    delete[] arr1;                                          // delete first temporary sub-array 
    delete[] arr2;                                          // delete second temporary sub-array
}