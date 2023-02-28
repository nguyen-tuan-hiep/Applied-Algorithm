#include<bits/stdc++.h>
using namespace std;

int t,n;

void solve(){
    //find integer pair (x,y) such that x^y*y + y^x*x = n
    for(int i = 2; i<=n; i++){
        for(int j = 2; j<=n; j++){
            if(pow(i,j)*j + pow(j,i)*i == n){
                cout << i << " " << j << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fflush(stdin);
    freopen("exponential_equation.txt", "r", stdin);
    cin >> t;
    while(t--){
        cin >> n;
        solve();
    }
    return 0;
}