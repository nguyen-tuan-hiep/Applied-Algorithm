#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[100000];

void input(){
    cin >> n;
    cin >> k;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
}

void solve(){
    map<int,int> m;
    for(int i = 0; i<n; i++){
        int components = k-a[i];
        if(m.count(components)==0){
            m.insert({a[i],i});
        }
        else{
            cout<< i << " " << m[components] << endl;
        }
    }
}

int main(){
    input();
    solve();
    return 0;
}