// Given a undirected connected graph G=(V,E) where V={1,…,N}. Each edge (u,v)∈E(u,v)∈E has weight w(u,v)w(u,v). Compute minimum spanning tree of G.
// Input
// Line 1: N and M (1≤N,M≤10^5)
// in which NN is the number of nodes and MM is the number of edges.
// Line i+1 (i=1,…,M): contains 3 positive integers u, v, and w where w is the weight of edge (u,v)
// Output
// Write the weight of the minimum spanning tree found.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define iii pair<int,ii>

int n, m, par[100005], res;
vector<iii> e;

int get(int u){
    if(par[u] < 0) return u;
    return par[u] = get(par[u]);
}

void join(int u, int v){
    u = get(u);
    v = get(v);
    if(u == v) return;
    if(par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
}

void input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back(make_pair(w, make_pair(u, v)));
    }
}

void solve(){
    sort(e.begin(), e.end());
    memset(par, -1, sizeof(par));
    for(int i = 0; i < m; i ++){
        int u = e[i].second.first, v = e[i].second.second, w = e[i].first;
        if(get(u) != get(v)){
            join(u, v);
            res += w;
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    solve();
    return 0;
}

