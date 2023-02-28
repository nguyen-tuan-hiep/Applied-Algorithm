#include<bits/stdc++.h>
using namespace std;

// check if a graph is bipartile

class Graph{
    int V;
    list<int> *adj;
    bool isBipartileUtil(int s, bool visited[], int color[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isBipartile();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isBipartileUtil(int s, bool visited[], int color[])
{
    visited[s] = true;
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
    {
        if (!visited[*i])
        {
            color[*i] = 1 - color[s];
            if (!isBipartileUtil(*i, visited, color))
                return false;
        }
        else if (color[*i] == color[s])
            return false;
    }
    return true;
}

bool Graph::isBipartile()
{
    bool *visited = new bool[V];
    int *color = new int[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        color[i] = -1;
    }
    for (int i = 0; i < V; i++)
        if (!visited[i])
            if (!isBipartileUtil(i, visited, color))
                return false;
    return true;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    if (g.isBipartile())
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
