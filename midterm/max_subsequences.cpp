#include<bits/stdc++.h>
using namespace std;
#define N 100000
int n;
int a[N];
int mem[N];
int sum = 0;
int minElement = INT_MAX;

void input(){
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        mem[i] = a[i];
    }
}

void solve(){
    for(int i = 1; i<=n; i++){
        sum += a[i];
        minElement = min(minElement, a[i]);
    }
    if(n == 1){
        cout << a[1] << endl;
        return;
    }
    if(n == 2){
        cout << sum << endl;
        return;
    }
    if(n == 3){
        cout << sum - minElement << endl;
        return;
    }
    mem[1] = a[1];
    mem[2] = a[1] + a[2];
    mem[3] = max(mem[2], max(mem[1] + a[3], a[2] + a[3]));
    for(int i = 4; i<=n; i++)
        mem[i] = max(mem[i-1], max(mem[i-2] + a[i], mem[i-3] + a[i] + a[i-1]));
    cout << mem[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();    
}