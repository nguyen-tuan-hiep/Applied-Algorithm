#include<bits/stdc++.h>
using namespace std;
#define N 100
int n;
int c[N][N];
int used[N];
int x[N];   // x[1]= 2 means job 1 is assigned for worker 2
int fopt;
int f, g;
int cmin;
int xopt[N];

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin >> c[i][j];
    }
}

void init(){
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            cmin = min(cmin,c[i][j]);
    fopt = INT16_MAX;
    memset(used, 0, sizeof(used));
    memset(xopt, 0, sizeof(xopt));    
}

int check(int v, int k){
    if(used[v]==1)  return 0;
    return 1;
}

void Try(int k){
    for(int v = 1; v<=n; v++){
        if(check(v,k)){
            x[k] = v;
            used[v] = 1;
            f += c[k][v];
            g = f + (n-k+1)*cmin;
            if(k==n){
                if(fopt>f){
                    fopt = f;
                    for(int i=1;i<=n;i++)
                        xopt[i] = x[i];
                }
            }
            else if(g<fopt){
                Try(k+1);
            }
            used[v] = 0;
            f -= c[k][v];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fflush(stdin);
    freopen("test.txt", "r", stdin);
    input();
    init();
    Try(1);
    cout << fopt << endl;
    for(int i = 1; i <= n; i++){
        printf("Job %d: Worker %d\n", i, xopt[i]);
    }
    return 0;
}