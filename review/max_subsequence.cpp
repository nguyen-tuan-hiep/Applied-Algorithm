#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000000];
int end_ = 0, start = 0;

void input(){
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
}

void solve(){
    int maxSum = 0;
    int curSum = 0;
    for(int i = 1; i<=n; i++){
        curSum += a[i];
        maxSum = max(maxSum, curSum);
        if(maxSum == curSum)    end_ = i;
        if(curSum < 0){
            start = i+1;
        }
        curSum = max(curSum, 0);
        
    }
    
    cout << maxSum << endl;
    cout << start << " " << end_ << endl;
}

int main(){
    input();
    solve();
    return 0;
}