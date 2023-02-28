#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int n;
long long a[N];
long long S0[N];
long long S1[N];
bool B0[N];
bool B1[N];

void input(){
    cin >> n;
    for(int i = 1; i<=n;i++)
        // cin >> a[i];
        scanf("%lld",&a[i]);
}

void solve(){
    if(a[1]%2==0){
        S0[1] = a[1];
        B0[1] = true;
        B1[1] = false;
    }
    else{
        S1[1] = a[1];
        B1[1] = true;
        B0[1] = false;
    }
    for(int i = 2; i<=n;i++){
        if(a[i]%2==0){
            if(B0[i-1]){
                if(S0[i-1]>0)
                    S0[i] = S0[i-1] + a[i];
                else S0[i] = a[i];
                B0[i] = true;
            }
            else{
                S0[i] = a[i];
                B0[i] = true;
            }
            if(B1[i-1]){
                S1[i] = S1[i-1] + a[i];
                B1[i] = true;
            }
            else    B1[i] = false;
        }else{
            if(B1[i-1]){
                S0[i] = S1[i-1] + a[i];
                B0[i] = true;
            }else   B0[i] = false;
            if(B0[i-1]){
                if(S0[i-1]>0)
                    S1[i] = S0[i-1] + a[i];
                else S1[i] = a[i];
                B1[i] = true;
            }
            else{
                S1[i] = a[i];
                B1[i] = true;
            }
        }  
    }
    long long ans = -1e18;
    for(int i = 1; i<=n;i++){
        if(B0[i] && ans < S0[i])
            ans = S0[i];
    }
    cout << ans << endl;
}

int main(){
    input();
    solve();
}