#include <bits/stdc++.h>
using namespace std;
#define N 5001
#define INF 1000000000
int w[N][N]; // w[u][v] is the weight of the arc(u,v)
int n,m;
int C[N], D[N];
int d[N]; // d[i] is the distance from the source to i during the BFS
bool f[N]; // f[v] = true means that the shortest path from s to v was found
vector<int> A[N]; // A[v] is the list of adjacent cities of v

void BFS(int i){
    queue<int> Q;
    for(int j = 1; j <= n; j++) d[j] = -1;
    d[i] = 0; Q.push(i);
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        //cout << "BFS(" << i << ") POP v = " << v << endl;
        w[i][v] = C[i];// weight of the arc (i,v)  is the price of the bus at city i
        for(int j = 0; j < A[v].size(); j++){
            int u = A[v][j];
            if(d[u] >= 0) continue; // u has been visited
            d[u] = d[v] + 1;
            if(d[u] <= D[i]) Q.push(u);
            //cout << "BFS(" << i << ") PUSH u = " << u << endl;
        }
    }
}

void buildGraph(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            w[i][j] = INF;
    for(int i = 1; i <= n; i++){
        BFS(i);
    }
}

void dijkstra(int s, int t){
    for(int v = 1; v <= n; v++){ d[v] = w[s][v]; f[v] = false;}
    d[s] = 0; f[s] = true;
    for(int i = 1; i <= n; i++){
        int u = -1; int minD = INF;
        // select a node u having minimum d[u]
        for(int v = 1; v <= n; v++) if(!f[v]){
            if(d[v] < minD){ u = v; minD = d[v]; }
        }
        f[u] = true;
        if(u == t) break; // the result was found
        for(int v = 1; v <= n; v++) if(!f[v]){
            if(d[v] > d[u] + w[u][v]){
                d[v] = d[u] + w[u][v];
            }
        }
    }
    cout << d[t];
}

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> C[i] >> D[i];
    }
    for(int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
void solve(){
    buildGraph();
    dijkstra(1,n);
}

int main(){
    input();
    solve();
    return 0;
}
