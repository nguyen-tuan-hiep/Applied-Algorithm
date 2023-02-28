#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000];
int b;
int dau[999];
int curSum = 0;
int cnt=0;

void input(){
    cin >> n >> b;
    for(int i = 1; i<=n; i++)
        cin >> a[i];
}

int check(int v, int k){
    return 1;
}


void solve(int k){
    for(int v = -1; v <= 1; v+=2){
        if(check(v,k)){
            dau[k] = v;
            curSum += v*a[k+1];
            if(k+1==n){
                if(curSum == b){
                    cnt++;
                }
            }    
            else solve(k+1);
            curSum -= v*a[k+1];
        }
    }
}

int main(){
    input();
    curSum = a[1];
    solve(1);
    cout << cnt << endl;
    return 0;
}
