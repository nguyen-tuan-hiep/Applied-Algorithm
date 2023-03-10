#include<bits/stdc++.h>
using namespace std;

// write a program that visit nodes of G by a BFS (consider a lexicorgraphic order of nodes)
// input: number of vertices and edges, edge between two vertices
// output: sequence of nodes visited by BFS
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

int n,m;
vector<int> graph[100001];
bool visited[100001];

void input(){
    cin >> n >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void bfs(){
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int i = 0; i<graph[u].size(); i++){
            if(!visited[graph[u][i]]){
                q.push(graph[u][i]);
                visited[graph[u][i]] = true;
            }
        }
    }
}


int main(){
    input();
    for(int i = 1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    bfs();
    return 0;
}