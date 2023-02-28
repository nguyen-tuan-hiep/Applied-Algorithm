#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void DFS_topo(int s, bool visited[], stack<int> &Stack);
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
    adj[v].push_back(w);
}

void Graph::DFS_topo(int s, bool visited[], stack<int> &Stack)
{
    visited[s] = true;
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!visited[*i])
            DFS_topo(*i, visited, Stack);
    Stack.push(s);
}

void Graph::topologicalSort()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFS_topo(i, visited, Stack);
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    Graph g(10);
    g.addEdge(9, 6);
    g.addEdge(6, 3);
    g.addEdge(0, 6);
    g.addEdge(6, 2);
    g.addEdge(3, 8);
    g.addEdge(3, 4);
    g.addEdge(0, 4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 7);
    g.addEdge(7, 8);
    g.addEdge(4, 5);
    g.addEdge(2, 5);
    cout << "Following is a Topological Sort of the given graph: ";
    g.topologicalSort();
    return 0;
}