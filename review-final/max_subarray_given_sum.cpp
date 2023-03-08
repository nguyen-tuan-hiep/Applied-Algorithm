#include<bits/stdc++.h>
using namespace std;

// https://www.techiedelight.com/find-maximum-length-sub-array-having-given-sum/

int n, target;
int a[100000];
void input(){
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter array: ";
    for(int i = 0; i<n; i++)
        cin >> a[i];
    cout << "Enter target: ";
    cin >> target;
}

void solve(){
    int len = 0, end = -1;
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += a[j];
            if(sum == target){
                if (len < j - i + 1){
                    len = j - i + 1;
                    end = j;
                }
            }
        }
    }
    printf("[%d, %d]", end - len + 1, end);
}

int main(){
    input();
    solve();
    return 0;
}