#include<bits/stdc++.h>
using namespace std;

int n, cnt;
int a[100];

void printSoltion(){
    int i;
    cnt ++;
    cout << "String # " << cnt << ": ";
    for(int i = 0;i<n;i++){
        cout << a[i];
    }
    cout << endl;
}

void Try(int k){
    for(int i = 0; i<=1; i++){
        a[k] = i;
        if(k==n-1)     printSoltion();
        else Try(k+1);
    }
}

int main(){
    cout << "Enter n = ";
    cin >> n;
    Try(0);
    cout << "Number of strings " << cnt;
}