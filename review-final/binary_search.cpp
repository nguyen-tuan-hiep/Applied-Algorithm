#include<bits/stdc++.h>
using namespace std;

int n, target;
int a[10000];

void input(){
    cin >> n;
    for(int i = 0; i< n; i++)   cin >> a[i];
    cin >> target;
}

int solve(int low, int high){
    if(low > high)  return -1;
    int mid = low + (high - low)/2;
    if(a[mid] == target)    return mid;
    else if(target < a[mid])    return solve(low, mid-1);
    return solve(mid+1, high);
}

int main(){
    input();
    int low = 0, high = n-1;
    cout << solve(low, high);
    return 0;
}