#include"GraphMatrix.cpp"
void BFS(Graph &,int);
void BFS(Graph &g , int source)
{
    queue<int> q ;
    q.push(source);
    bool status[g.totalVertices()] ;
    for(int i=0 ; i<g.totalVertices() ; i++)
        status[i] = 0 ;
    status[source] = true ;
    int n , u ;    
    while(!q.empty())
    {
        n = q.front();
        cout << "V" << n << " ";
        q.pop();
        vector<int> adjacent = g.getAdjacent(n);
        for(int j=0 ; j<adjacent.size() ; j++)
        {
            u = adjacent[j];
            if(status[u]==false)
            {
                q.push(u);
                status[u] = true ;
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