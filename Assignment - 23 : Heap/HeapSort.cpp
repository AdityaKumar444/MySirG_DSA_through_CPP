#include"Heap.cpp"
int * HeapSort(Heap &);
int * HeapSort(Heap &h)
{
    Heap h1 = h ;
    int *ptr = new int[h1.size()] ;
    for(int i=h1.size()-1 ; i>=0 ; i--)
        ptr[i] = h1.Delete();
    return ptr ;
}
int main()
{
    Heap h(6);
    h.insert(20);
    h.insert(60);
    h.insert(30);
    h.insert(50);
    h.insert(70);
    h.insert(40);
    h.insert(10);
    h.insert(110);
    h.insert(80);
    h.insert(90);
    h.insert(35);
    h.insert(55);
    h.insert(75);
    h.insert(91);
    h.insert(49);
    int *ptr = HeapSort(h);
    for(int i=0 ; i<h.size() ; i++)
        cout << ptr[i] << " " ;
    return 0 ;
}