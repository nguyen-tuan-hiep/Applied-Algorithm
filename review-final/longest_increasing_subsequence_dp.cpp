// Problem statement:
// You are given an array of n integers, and your task is to find the length of the longest increasing subsequence 
// (not necessarily contiguous) in the array. 
// For example, in the array [10, 22, 9, 33, 21, 50, 41, 60], the longest increasing subsequence is [10, 22, 33, 50, 60], which has length 5.

// Solution:
// We can solve this problem using dynamic programming. 
// We create an array dp where dp[i] represents the length of the longest increasing subsequence ending at index i. 
// We can define dp[i] as follows:

// dp[i] = max(dp[j] + 1) for all j < i and nums[j] < nums[i]

// That is, the length of the longest increasing subsequence ending at index i is the maximum length of all 
// increasing subsequences that end at an index j that comes before i, where nums[j] is less than nums[i]. 
// If no such j exists, then dp[i] is simply 1, as the longest increasing subsequence ending at index i is just the element at index i.
// To find the overall longest increasing subsequence in the array, we simply iterate through the dp array and find the maximum value.

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<int> dp;

void input(){
    cin >> n;
    a.resize(n+1);
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
}

void solve(){
    dp.resize(n+1);
    dp[1] = 1;
    int maxLen = dp[1];
    for(int i = 2; i<=n; i++){
        dp[i] = 1;
        for(int j = 1; j<i; j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    cout << maxLen << endl;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}