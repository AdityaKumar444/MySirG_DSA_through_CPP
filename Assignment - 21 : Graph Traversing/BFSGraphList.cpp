#include"GraphList.cpp"
void BFS(Graph &,int);
void BFS(Graph &G,int source)
{
    queue<int> q ;
    bool status[G.totalVertices()];
    q.push(source);
    for (int i = 0 ; i < G.totalVertices() ; i++)
        status[i] = false ;
    status[source] = true ;
    int n , u ;
    while(!q.empty())
    {
        n = q.front();
        cout << "V" << n << " ";
        q.pop();
        queue<int> adjacent = G.getAdjacent(n);
        while(!adjacent.empty())
        {
            u = adjacent.front();
            if(status[u]==false)
            {
                q.push(u);
                status[u] = true ;
            }
            adjacent.pop();
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