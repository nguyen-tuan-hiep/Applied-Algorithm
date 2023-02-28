#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
int a[N], S[N];
int n, L1, L2, ans;

void input(){
    cin >> n >> L1 >> L2;
    for(int i = 1; i<=n; i++)
        scanf("%d",&a[i]);
}

void solve(){
    deque<int> d;
    ans = 0;
    for(int i = 1; i<=n;i++){
        while(!d.empty() && d.front() < i-L2)
            d.pop_front();
        int j = i - L1;
        if(j>=1){
            while(!d.empty() && S[d.back()] < S[j])
                d.pop_back();
            d.push_back(j);
        }
        S[i] = a[i] + (d.empty() ? 0 : S[d.front()]);
        ans = max(ans,S[i]);
    }
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}