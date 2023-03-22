#include<bits/stdc++.h>
using namespace std ; 
struct node
{
    int vertex ;
    node *next ;
    int weight ;
};
class AdjList
{
    private:
        node *start ;    // creating start variable which contains list address
        int vertex ;     // creating starting vertex for each list which will have adjacent vertices
    public:
        AdjList(int v)
        {
            start = nullptr ;
            vertex = v ;
        }
        AdjList()
        {
            start = nullptr ;
        }
        void addNode(int,int);      // method for adding nodes to the list 
        void setVertex(int);        // method for setting starting vertex of the list
        void deleteNode();          // method for deletion of the list
        void printList();           // method for printing the list
        ~AdjList()
        {
            while(start!=nullptr)
                deleteNode();
        }
};
void AdjList::deleteNode()
{
    if(start!=nullptr)
    {  
        node *temp = start ;
        start = start->next ;
        delete temp ;
    }
}
void AdjList::printList()
{
    node *t = start ;
    while(t!=nullptr)
    {
        cout << "V" << t->vertex << "->" << t->weight << " , " ;
        t = t->next ;
    }
}
void AdjList::setVertex(int v)
{
    vertex = v ;
}
void AdjList::addNode(int v , int data)
{
    node *n = new node ;
    n->vertex = v ;
    n->weight = data ;
    n->next = start ;
    start = n ;
}
class Graph
{
    private:
        int v_count ;
        AdjList *arr ;  
    public:
        Graph();
        void createGraph(int);      // method for creating the graph
        void printGraph();          // method for printing the graph
        ~Graph();
};
Graph::~Graph()
{
    delete[] arr ;
}
void Graph::printGraph()
{
    for(int i=0 ; i<v_count ; i++)
    {
        cout << "V" << i << "--> ";
        arr[i].printList();
        cout << endl ;
    }
}
void Graph::createGraph(int v)
{
    v_count = v ;
    int n , w , v_no;
    arr = new AdjList[v_count];
    for(int i=0 ; i<v_count ; i++)
    {
        arr[i].setVertex(i);
        cout << "\nEnter no. of adjacent vertexes to V" << i << " : " ;
        cin >> n ;
        for(int j=0 ; j<n ; j++)
        {
            cout << "\nEnter vertex no. and weight associated to it : " ;
            cin >> v_no >> w ;
            arr[i].addNode(v_no,w); 
        } 
    }
}
Graph::Graph()
{
    v_count = 0 ;
    arr = nullptr ;
}
int main()
{
    Graph g ;
    g.createGraph(6);
    g.printGraph();
}