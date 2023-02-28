#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[100000];
double res=0;

void input(){
    cin >> n >> k;
    for(int i = 1; i<=n; i++)
        cin >> a[i];
}

void solve(){
    // for loop to find subset of array a with size >= k with max average
    
    for(int i = 1; i<=n; i++){
        for(int j = i; j<=n; j++){
            int sum = 0;
            for(int t = i; t<=j; t++){
                sum += a[t];
            }
            if(j-i+1 >= k){
                res = max(res, (double)sum/(j-i+1));
            }
        }
    }
    cout << res << endl;
}

int main(){
    input();
    solve();
    return 0;
}