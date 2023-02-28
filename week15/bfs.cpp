#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;          // no. of vertices
    list<int> *adj; // pointer to an array containing adjacency lists
    bool *visited;
    int *pred;
    Graph(int V); // Constructor
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{ // directed graph
    adj[u].push_back(v);
}

void Graph::BFS(int s)
{
    visited[s] = 1;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front(); // lay phan tu dung dau hang doi nhung khong xoa no khoi hang doi
        Q.pop();           // xoa phan tu khoi hang doi
        cout << " " << u;
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = *i;
            if (visited[v] == 0)
            {
                visited[v] = 1;
                Q.push(v);
                pred[v] = u;
            }
        }
    }
}

int main()
{
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 0);
    g.addEdge(3, 0);
    g.addEdge(0, 2);

    // Init
    g.visited = new bool[g.V];
    g.pred = new int[g.V];
    for (int i = 0; i < g.V; i++)
    {
        g.visited[i] = false;
        g.pred[i] = -1;
    }

    cout << "BFS(1): ";
    g.BFS(1);

    cout<<endl;

    int u = 0;
    while (g.pred[u] != -1)
    {
        cout << u << "<-";
        u = g.pred[u];
    }
    cout << "1";
    return 0;
}