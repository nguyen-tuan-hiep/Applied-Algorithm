#include<bits/stdc++.h>
using namespace std;

int a[1000];
int mem[1000];
bool solved[1000] = {0};
int n;

void input(){
    cout << "Enter n: ";
    cin >> n;
    for(int i = 0; i<n; i++){
        cout << "Enter a[" << i << "]: ";
        cin >> a[i];
    }
}

int maxsum(int i){
    if(i==1)    return a[1];
    if(solved[i])    return mem[i];
    int res = max(a[i], a[i]+maxsum(i-1));
    mem[i] = res;
    solved[i] = 1;
    return res;
}
int main(){
    input();

    int maximum = 0;
    int indexLast = -1;
    for(int i = 1; i<=n;i++){
        if(maximum<mem[i]){
            maximum = mem[i];
            indexLast = i;
        }
    }
    // tong phan tu = maximum
    // phan tu cuoi cung o chi so indexLast
    for(int i=indexLast; i>=1; i--){
        int t = maximum - a[i];
        if(t<0) break;
    }
}