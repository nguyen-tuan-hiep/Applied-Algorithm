#include<bits/stdc++.h>
using namespace std;

int n;
int a[100000];
int k,A,B;
int res = 0;

void input(){
    cin >> n >> k >> A >> B;
    for(int i = 1; i<=n; i++)
        cin >> a[i];
}


void solve(){
    for(int i = 1; i<=n-k+1; i++){
        for(int j = i+k-1; j<=n; j++){
            int sum = 0;
            for(int t = i; t<=j; t++){
                sum += a[t];
            }
            if(j-i+1 == k && sum >= A && sum <= B){
                res++;
            }
        }
    }
    cout << res << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // fflush(stdin);
    // freopen("2-input.txt", "r", stdin);
    input();
    solve();    
}