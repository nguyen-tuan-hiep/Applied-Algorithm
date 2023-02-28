#include<bits/stdc++.h>
using namespace std;

int n;
int a[100000];

void input(){
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
}

void solve(){
    int count = 1;
    for(int i = 0; i<n-1; i++){
        if(a[i]>a[i+1])
            count++;
    }
    cout << count << endl;
}

int main(){
    input();
    solve();
    return 0;
}