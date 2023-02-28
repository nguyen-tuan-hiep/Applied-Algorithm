#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000];
void input(){
    cin >> n;
    for(int i = 0; i<n;i++){
        cin >> a[i];
    }
}

void solve(){
    int Q = 0;
    int P = 1000000007;
    for(int i=0;i<n-1;i++){
        for(int j = i+1; j<n; j++){
            if(a[i] > a[j]){
                
                Q++;
                Q = Q%P;
            }
        }
    }
    cout << Q;
}

int main(){
    input();
    solve();
    return 0;
}