#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000];

int main(){
    cin >> n;
    for(int i = 1; i<=n; i++)
        cin >> a[i];
    int cnt = 0;
    for(int i = 2; i<=n-1;i++){
        if(a[i]> a[i-1] && a[i]>a[i+1])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}