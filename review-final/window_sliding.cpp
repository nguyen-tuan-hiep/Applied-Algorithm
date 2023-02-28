#include<bits/stdc++.h>
using namespace std;

//Problem Statement:
// Given an array of integers and a window size k, find the maximum value in each window of size k.

vector<int> a;
int n, k;
int res = 0;

void input(){
    cin >> n >> k;
    a.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}


//optimize the solve function
void solve(){
    int sum = 0;
    for(int i = 1; i<=k;i++){
        sum += a[i];
    }
    res = max(res, sum);
    for(int i = k+1; i<=n;i++){
        sum += a[i] - a[i-k];
        res = max(res, sum);
    }
    cout << "result: " << res;
}

int main(){
    input();
    solve();
}

