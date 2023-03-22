#include<bits/stdc++.h>
using namespace std ; 
class Graph
{
    private:
        int v_count ;
        int e_count ;
        int **adj ;
    public:
        Graph();
        void createGraph(int,int);
        void printGraph();
        void printAdjacent(int);
        bool isIsolated(int);
        ~Graph();
};
Graph::~Graph()
{
    for(int i=0 ; i<v_count ; i++)
        delete[] adj[i] ;
    delete[] adj ;
}
bool Graph::isIsolated(int vertex)
{
    if(vertex < v_count && vertex >=0)
    {
        for(int i=0 ; i<v_count ; i++)
        {
            if(adj[vertex][i]==1)
                return true ;
        }
    }
    return false ;
}
void Graph::printAdjacent(int vertex)
{
    if(vertex < v_count && vertex >=0)
    {
        cout << endl ;
        for(int i=0 ; i<v_count ; i++)
        {
            if(adj[vertex][i]==1)
                cout << i << endl ;
        }
    }
}
void Graph::printGraph()
{
    cout << endl ;
    for(int i=0 ; i<v_count ; i++)
    {
        for(int j=0 ; j<v_count ; j++)
        {
            cout << adj[i][j] << " " ;
        }
        cout << endl ;
    }
}
void Graph::createGraph(int vertex , int edge)
{
    v_count = vertex ;
    e_count = edge ;
    adj = new int*[vertex] ;                                // array of pointers created dynamically
    for(int i=0 ; i<vertex ; i++)                           // assigning reference of arrays to pointers
        adj[i] = new int[vertex] ;
    memset(adj,0,vertex);                                   // assigning zero to every location
    int u , v ;
    for(int i=1 ; i<=e_count ; i++)
    {
        cout << "Enter vertex numbers adjacent to each other : " ;
        cin >> u >> v ;
        adj[u][v] = 1 ;
        adj[v][u] = 1 ;
        cout << endl ;
    }
}
Graph::Graph()
{
    v_count = 0 ;
    e_count = 0 ;
    adj = nullptr ;
}