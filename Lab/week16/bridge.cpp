#include <bits/stdc++.h>

using namespace std;
const long N = 100000 + 7;
const long INF = 1000000000 + 7;
const long MODULE = 1000000000 + 7;
typedef pair<int,int> ii;

int n, m;
int d[N], p[N], khop[N], cau[N], num[N], low[N], ca[N], child[N];
vector <int> a[N];
int t;
void input(){
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
}

void dfs(int u){
	t ++;
	num[u] = t;
	low[u] = num[u];
	for (int i = 0; i < a[u].size(); i++) {
		int v = a[u][i];
		if ( v == p[u] ) continue;

		if ( num[v] ) {
			low[u] = min(low[u] , num[v] );
		}
		else {
			p[v] = u;
			dfs(v);
			low[u] = min(low[u] , low[v]);
		}
	}

}
int main(){
	input();
	int anskhop = 0, anscau = 0;
	t = 0;
	for (int i = 1; i <= n; i++) {  if ( !num[i] ) dfs(i);	}
	for (int i = 1; i <= n; i++) {
		int v = p[i];
		if (v > 0) child[v]++;
	}
	for (int i = 1; i <= n; i++) {
		int u = p[i];
		if ( u > 0 && p[u] > 0 && low[i] >= num[u] ) khop[u] = 1;
	}
	for (int i = 1; i <= n; i++) {   if ( p[i] == 0 && child[i] >= 2 ) khop[i] = 1;	}

	for (int i = 1; i <= n; i++) anskhop += khop[i] == 1;
	for (int i = 1; i <= n; i++) {   if ( p[i] != 0 && low[i] >= num[i] ) ++anscau;	}

	cout << anskhop << " " << anscau << endl;
	return 0;
}
