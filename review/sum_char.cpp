// HUST + SOICT = N.
// x[0] = H, x[1] = U, x[2] = S, x[3] = T, x[4] = O, x[5] = I, x[6] = C

#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int t,n, cnt;
int x[MAX];
int visited[MAX];

int check(int v, int k){
    if(v==0 && k == 0)   return 0;
    if(v==0 && k == 2)   return 0;
    if(visited[v] == 1)  return 0;
    return 1;
}

void solution(){
    int res = x[0]*1000 + x[1]*100 + x[2]*10 + x[3] + x[2]*10000 + x[4]*1000 + x[5]*100 + x[6]*10 + x[3];
    if(res == n){
        cnt++;
    }
}

void Try(int k){
    for(int v = 0; v<=9; v++){
        if(check(v,k)){
            x[k] = v;
            visited[v] = 1;
            if(k==6)    solution();
            else        Try(k+1);
            visited[v] = 0;
        }
    }
}

int main(){
    cin >> t;
    while(t--){
        for(int i = 0; i<=9; i++)
            visited[i] = 0;
        cin >> n;
        cnt = 0;
        Try(0);
        cout << cnt << endl;
    }
}