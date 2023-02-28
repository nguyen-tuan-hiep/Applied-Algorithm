#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int W, int n,int val[], int wt[]){
    int dp[W+1];
    memset(dp, 0, sizeof dp);
    for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);

    return dp[W];
}
int main(){
    int W = 19;
    int val[] = {25,12,6,24,21};
    int wt[] = {5, 2,3,6,6};
    int n = sizeof(val)/sizeof(val[0]);

    cout << unboundedKnapsack(W, n, val, wt);

    return 0;
}
