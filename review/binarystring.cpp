#include<bits/stdc++.h>
using namespace std;

int n;
int x[10000];

void  input(){
    cin >> n;
}

void printSolution(){
    for(int i = 1; i<=n; i++)
        cout << x[i];
    cout << endl;
}

int check(int v, int k){
    if(x[k-1] + v >1)   return 0;
    return 1;
}

void Try(int k){
    for(int v= 0; v<=1; v++){
        if(check(v,k)){
            x[k] = v;
            if(k==n)    printSolution();
            else        Try(k+1);
        }
    }
}


int main(){
    input();
    Try(1);
    return 0;
}