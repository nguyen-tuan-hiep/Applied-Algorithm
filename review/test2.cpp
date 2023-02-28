#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[100][100];
int cnt = 0;
int flag = 1;

void input(){
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        for(int j= 1; j<=m; j++){
            cin >> a[i][j];
        }
    }
}

void solve(){
    for(int j = 1; j<=m; j++){
        int i=0;
        for(i= 1; i<=n; i++){
            if(a[i][j] == 0)   break;  
        }
        if(i>n) cnt++;
    }
}

int main(){
    input();
    solve();
    cout << cnt << endl;
    return 0;
}