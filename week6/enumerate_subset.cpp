#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[100];

void printSolution(){
    for(int i = 1; i<= m;i++)
        cout << a[i] << " ";
    cout << endl;
}

void Try(int k){
    for(int i = a[k-1]+1; i<=n-m+k; i++){
        a[k] = i;
        if(k==m)    printSolution();
        else    Try(k+1);
    }
}

int main(){
    cout << "Enter n: ";
    cin >> n;   
    cout << "Enter m: ";
    cin >> m;
    Try(1);
}