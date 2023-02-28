// using branch and bound to solve travelling salesman problem with

#include<bits/stdc++.h>
using namespace std;

int n;
int a[100][100]; // a[i][j] = cost of travelling from city i to city j
int x[100];     // x[i] = j means that the i-th city is visited at the j-th position

int currentCost, bestCost;
int visited[100];

void input(){
    cin >> n;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            cin >> a[i][j];
}

void printSolution(){
    for(int i = 1; i<=n; i++)
        cout << x[i] << " ";
    cout << endl;
}

bool check(int v, int k){
    return visited[v] == 1;
}

void Try(int k){
    for(int v = 1; v<=n;v++){
        if(check(v,k)){
            x[k] = v;
            visited[v] = 1;
            currentCost += a[k-1][v];
            if(k==n){
                printSolution();
                bestCost = min(bestCost, currentCost);
            
            }else if(bestCost > currentCost){
                Try(k+1);
            }
            currentCost -= a[k-1][v];
            visited[v] = 0;
            
        }
    }
}

int main(){
    input();
    currentCost = 0;
    bestCost = INT_MAX;
    for(int i = 1; i<=n; i++)
        visited[i] = 0;
    x[1] = 1;
    visited[1] = 1;
    Try(2);
    return 0;
}
