#include<bits/stdc++.h>
using namespace std;
#define N 100

int mem[N];

int fibonacci(int n){
    // if n is in mem, return mem[n] else calculate and store in mem
    if(mem[n]==-1){
        if(n<=1)   mem[n] = n;
        else    mem[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return mem[n];
}

int main(){
    memset(mem, -1, sizeof(mem));
    cout << fibonacci(10);
    return 0;
}