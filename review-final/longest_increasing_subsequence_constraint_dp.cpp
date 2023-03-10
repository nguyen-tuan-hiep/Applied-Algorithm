// Problem statement:
// You are given an array of n integers. Your task is to find the length of the longest increasing subsequence 
// (not necessarily contiguous) in the array, subject to the additional constraint that no two adjacent 
// elements in the subsequence can have a difference of exactly one. For example, 
// in the array [1, 2, 3, 4, 5, 6, 7, 8, 10], the longest increasing subsequence subject to the constraint has length 5, and is [1, 3, 5, 7, 10].

// Write a C++ function that takes an array of integers as input and returns the length of the longest increasing subsequence subject to the constraint.

// Solution:
// We can solve this problem using dynamic programming. We create an array dp where dp[i] represents 
// the length of the longest increasing subsequence ending at index i, subject to the constraint that no 
// two adjacent elements in the subsequence can have a difference of exactly one. We can define dp[i] as follows:
// dp[i] = max(dp[j] + 1) for all j < i and nums[j] + 1 < nums[i] and nums[j] - 1 > nums[i]
// That is, the length of the longest increasing subsequence ending at index i, subject to the constraint, 
// is the maximum length of all increasing subsequences that end at an index j that comes before i, 
// where nums[j] is less than nums[i] by more than one. If no such j exists, 
// then dp[i] is simply 1, as the longest increasing subsequence ending at index i is just the element at index i.
// To find the overall longest increasing subsequence subject to the constraint in the array, 
// we simply iterate through the dp array and find the maximum value.


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
            if(abs(a[j] - a[i]) > 1){
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