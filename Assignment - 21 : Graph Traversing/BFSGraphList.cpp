#include"GraphList.cpp"
void BFS(Graph &,int);
void BFS(Graph &G,int source)                       // passing graph and source node
{
    queue<int> q ;                                  // creating queue to store vertexes
    bool status[G.totalVertices()];                 // creating boolean array for visited and unvisited vertices
    q.push(source);                                 // inserting the visited vertex
    for (int i = 0 ; i < G.totalVertices() ; i++)   // setting all vertices unvisited initially 
        status[i] = false ;
    status[source] = true ;                         // setting source vertex visited
    int n , u ;
    while(!q.empty())                               // iterating until queue becomes empty
    {
        n = q.front();                              // taking out front element of queue to find adjacent vertices to it
        cout << "V" << n << " ";
        q.pop();                                    // poping from queue
        queue<int> adjacent = G.getAdjacent(n);     // getting all adjacent vertices of n and storing in another queue
        while(!adjacent.empty())                    // iterating until all adjacent vertices are visited 
        {
            u = adjacent.front();                   // going to first adjacent vertex from n
            if(status[u]==false)                    // checking if that adjacent vertex is visited or not
            {
                q.push(u);                          // if not visited then pushing it in queue
                status[u] = true ;                  // updating adjacent vertex status to true
            }
            adjacent.pop();                         // poping from adjacent queue to access another vertex
        }
    }
}
int main()
{
    Graph G ;
    G.createGraph(6);
    BFS(G,2);
    return 0 ;
}