// generate combinations of k elements from a list n elements without order
// example: n = 5, k = 3
// 1 2 3 and 3 2 1 is the same combination

#include<bits/stdc++.h>
using namespace std;

int n, k;
int x[10000];
int visited[10000];

void  input(){
    cin >> n >> k;
}

void printSolution(){
    for(int i = 1; i<=k; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Try(int m){
    for(int v= x[m-1]+1; v<=n; v++){
        if(!visited[v]){
            x[m] = v;
            visited[v] = 1;
            if(m==k)    printSolution();
            else        Try(m+1);
            visited[v] = 0;
        }
    }
}

int main(){
    input();
    for(int i = 1; i<=n; i++)
        visited[i] = 0;
    Try(1);
    return 0;
}