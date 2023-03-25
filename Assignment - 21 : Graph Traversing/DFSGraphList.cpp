#include"GraphList.cpp"
void BFS(Graph &,int);
void BFS(Graph &G,int source)
{
    stack<int> q ;
    bool status[G.totalVertices()];
    q.push(source);
    for (int i = 0 ; i < G.totalVertices() ; i++)
        status[i] = false ;
    status[source] = true ;
    int n , u ;
    while(!q.empty())
    {
        n = q.top();
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
    G.createGraph(10);
    BFS(G,0);
    return 0 ;
}