#include<bits/stdc++.h>
using namespace std;
#define N 10000
int n,t;
int a[N];
int sum[N];

void input(){
    cin >> n >> t;
    for(int i = 1; i<=n;i++)
        cin >> a[i];
}

void findSum(){
    sum[1] = a[1];
    for(int i = 2; i<= n;i++){
        sum[i] = sum[i-1] + a[i]; 
    }
}

// j max on [low, high] | sum[j] <= target, sum[] ascending
int binary_search(int* sum, int low, int high, int target){
    while(low<=high){
        int mid = (low + high)/2;
        if(sum[mid] == target)  return mid;
        else if (sum[mid] < target)
            low = mid +1;
        else
            high = mid -1;
    }
    return high;
}

int main(){
    input();
    findSum();
    int result = 0;
    for(int i = 1; i<=n;i++){
        int j = binary_search(sum, i,n,t+sum[i]-a[i]);
        result = max(result,j-i+1);
    }
    cout << result << " " << endl;
}