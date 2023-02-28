// Problem statement:
// You are given an array of n integers, and your task is to find the maximum sum of a subsequence that is a contiguous subset of the array. For example, in the array [−2,1,−3,4,−1,2,1,−5,4], the maximum sum is 6, which is the sum of the subsequence [4,−1,2,1].

// Write a C++ function that takes an array of integers as input and returns the maximum sum of a contiguous subsequence.

// Solution:
// We can solve this problem using dynamic programming. We create an array dp where mem[i] represents the maximum sum of a contiguous subsequence ending at index i. The maximum sum of a contiguous subsequence ending at index i can be either the element at index i or the sum of the element at index i and the maximum sum of a contiguous subsequence ending at index i-1. Therefore, we can define dp[i] as follows:

// mem[i] = max(nums[i], nums[i] + mem[i-1])

// To find the maximum sum of a contiguous subsequence in the array, we simply iterate through the dp array and find the maximum value.


#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<int> mem;

void input(){
    cin >> n;
    a.resize(n+1);
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
}

void solve(){
    mem.resize(n+1);
    mem[1] = a[1];
    int maxSum = mem[1];
    for(int i = 2; i<=n; i++){
        mem[i] = max(a[i], a[i] + mem[i-1]);
        maxSum = max(maxSum, mem[i]);
    }
    cout << maxSum << endl;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}