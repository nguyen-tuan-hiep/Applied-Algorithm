#include<bits/stdc++.h>
using namespace std;

int n;
int x[100000];

void input(){
    cin >> n;
}

void printSolution(){
    for(int v = 1; v<=n; v++){
        cout << x[v] << " ";
    }
    cout << endl;
}

int check(int v, int k){
    for(int i = 1; i<k; i++){
        if(x[i]==v)
            return 0;
    }
    return 1;
}


void Try(int k){
    for(int v = 1; v<=n; v++){
        if(check(v,k)){
            x[k] = v;
            if(k==n)
                printSolution();
            else
                Try(k+1);
        }
    }
}


int main(){
    input();
    Try(1);
    return 0;
}