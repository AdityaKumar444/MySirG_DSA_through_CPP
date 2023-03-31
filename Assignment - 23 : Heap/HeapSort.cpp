#include"Heap.cpp"
void HeapSort(int *,int);
void HeapSort(int *arr , int size)
{
    Heap h(size) ;
    for(int i=0 ; i<size ; i++)
        h.insert(arr[i]);
    for(int i=size-1 ; i>=0 ; i--)
        arr[i] = h.Delete();
}
int main()
{
    int arr[15] = {20,60,30,50,70,40,10,110,80,90,35,55,75,91,49};
    HeapSort(arr,15);
    for(int i=0 ; i<15 ; i++)
        cout << arr[i] << " " ;
    return 0 ;
}