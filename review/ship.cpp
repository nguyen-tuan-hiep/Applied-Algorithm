// generate all permutations of a list n elements

#include<bits/stdc++.h>
using namespace std;

int n;
int x[10000];
int visited[10000];

void  input(){
    cin >> n;
}

void printSolution(){
    for(int i = 1; i<=n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Try(int k){
    for(int v= 1; v<=n; v++){
        if(!visited[v]){
            x[k] = v;
            visited[v] = 1;
            if(k==n)    printSolution();
            else        Try(k+1);
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
