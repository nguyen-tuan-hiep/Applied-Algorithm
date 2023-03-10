// Write a C++ program for the problem:
// Given a undirected graph =(V,E) in which V = {1,2,..,n} is the set of nodes. Write a program that visit nodes of G by a DFS (don't use pointer) (consider a lexicorgraphic order of nodes).
// Input
// Line 1: contains 2 integers n and m (1 <= n,m <= 100000)
// Line i+1: contains u and v which are two end-points of the ith edge

// Output
// Sequence of nodes visited by DFS
// Example
// Input
// 7 12
// 1 2
// 1 3
// 2 3
// 2 4
// 2 7
// 3 5
// 3 7
// 4 5
// 4 6
// 4 7
// 5 6
// 5 7
// Output
// 1 2 3 5 4 6 7

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> graph[100001];
bool visited[100001];

void input(){
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int start) {
    visited[start] = true;
    cout << start << " ";
    for (int i = 0; i < graph[start].size(); i++) {
        if (!visited[graph[start][i]]) {
            dfs(graph[start][i]);
        }
    }
}

int main() {
    input();
    for(int i = 1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }


    return 0;
}