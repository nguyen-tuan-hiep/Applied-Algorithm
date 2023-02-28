#include<bits/stdc++.h>
using namespace std;
 
class Graph
{
    int V;
    list<int> *adj;
    void BFS_topo(int s, bool visited[], queue<int> &Queue);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[w].push_back(v);
}

void Graph::BFS_topo(int s, bool visited[], queue<int> &Queue)
{
    visited[s] = true;
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!visited[*i])
            BFS_topo(*i, visited, Queue);
    Queue.push(s);
}

void Graph::topologicalSort()
{
    queue<int> Queue;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            BFS_topo(i, visited, Queue);
    while (Queue.empty() == false)
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

int main()
{
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(0, 2);
    g.addEdge(3, 0);
    g.addEdge(2, 4);
    
    cout << "Following is a Topological Sort of the given graph: ";
    g.topologicalSort();
    return 0;
}