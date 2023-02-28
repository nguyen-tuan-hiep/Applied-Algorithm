// find the sum of max subarray that does not contain 2 consecutive elements.
#include<bits/stdc++.h>
using namespace std;
#define N 100000
int n;
int a[N];
int mem[N];
int sum = 0;
int minElement = 9999;

void input(){
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        mem[i] = a[i];
    }
}

void solve(){
    for(int i = 3; i<=n; i++)
        mem[i] = max(mem[i-1], mem[i-2] + a[i]);
    cout << mem[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fflush(stdin);
    freopen("4-input.txt", "r", stdin);
    input();
    solve();    
}