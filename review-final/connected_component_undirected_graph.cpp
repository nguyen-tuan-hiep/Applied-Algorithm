// Given a undirected graph G=(V,E) where V={1,. . .,N} is the number of nodes and the set E has M edges. Compute the number of connected components of G.
// Input
// Line 1: two positive integers N and M (1 <= N <= 10^5, 1 <= M <= 10^5)
// Line i+1 (i=1, . . .,M): contains two positive integers u and v which are endpoints of i-th edge
// Output
// Write the number of connected components of G.

// Example
// Input
// 8 8
// 1 2
// 1 7
// 1 8
// 2 7
// 4 5
// 4 6
// 5 6
// 7 8

// Output
// 3



// This C++ program finds the number of connected components in a given undirected graph. 
// The program takes the number of nodes (n) and edges (m) of the graph as input. 
// It then takes each edge as input, one by one, and stores them in an adjacency list. 
// After the graph has been completely constructed, the program traverses each node and uses a breadth-first search algorithm to count the number of connected components. 
// If a node has not been visited, it is part of a new component, so the number of components is incremented. At the end, the total number of connected components is printed.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> graph[100005];
bool visited[100005];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int u, v;
    while (m--) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int numComponents = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i);
            numComponents++;
        }
    }
    cout << numComponents << endl;
    return 0;
}