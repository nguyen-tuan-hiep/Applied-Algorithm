#include<bits/stdc++.h>
using namespace std;

int n,k,m;
int a[20];
int res = 0;
void input(){
    cin >> n >> k >> m;
    for(int i = 1; i<=n; i++)
        cin >> a[i];
}

//find the number of ways to select k elements from an array such that the sum equal to m

void solve(){
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fflush(stdin);
    freopen("4-input.txt", "r", stdin);
    input();
    // solve(1,k,m);
    cout << res << endl;
}