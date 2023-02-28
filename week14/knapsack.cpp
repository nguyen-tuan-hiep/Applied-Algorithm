#include <bits/stdc++.h>
using namespace std;
 
int knapSack(int W, int wt[], int val[], int n){
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),knapSack(W, wt, val, n - 1));
}

int main(){
    int n,W;
    cout << "Enter numbers of items: ";    cin >> n;
    int val[n], wt[n];
    cout << "Enter value of each item: ";
    for(int i = 0; i<n;i++)         cin >> val[i];
    cout << "Enter weight of each item: ";
    for(int i = 0; i<n;i++)         cin >> wt[i];
    cout << "Enter capacity of knapsack: ";     cin >> W;
    cout << knapSack(W, wt, val, n);
    return 0;
}