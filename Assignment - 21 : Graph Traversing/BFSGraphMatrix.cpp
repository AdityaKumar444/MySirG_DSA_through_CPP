#include"GraphMatrix.cpp"
void BFS(Graph &,int);
void BFS(Graph &g , int source)       // passing graph and source node
{
    queue<int> q ;              // creating queue to store vertexes 
    q.push(source);             // inserting the visited vertex
    bool status[g.totalVertices()] ;        // creating boolean array for visited and unvisited vertices
    for(int i=0 ; i<g.totalVertices() ; i++)   // setting all vertices unvisited initially 
        status[i] = false ;
    status[source] = true ;     // setting source vertex visited
    int n , u ;    
    while(!q.empty())       // iterating until queue becomes empty
    {
        n = q.front();      // taking out front element of queue to find adjacent vertices to it 
        cout << "V" << n << " ";
        q.pop();            // poping from queue
        vector<int> adjacent = g.getAdjacent(n); // getting all adjacent vertices of n and storing in dynamic array
        for(int j=0 ; j<adjacent.size() ; j++) // iterating until all adjacent vertices are visited
        {
            u = adjacent[j];        // going to first adjacent vertex to n 
            if(status[u]==false)    // checking if that adjacent vertex is visited or not
            {
                q.push(u);          // if not visited pushing it in queue
                status[u] = true ;  // updating adjacent vertex status to visited
            }
        }
    }
    while(!q.empty())
    {
        cout << q.front() << " " ;
        q.pop();
    }
}
int main()
{
    Graph G ;
    G.createGraph(6,9);
    BFS(G,0);
    return 0 ;
}
