#include<bits/stdc++.h>
using namespace std;

int n, sum, currentSum, remain;
int coefficient[100];
int x[1000];

void input(){
    cin >> n;
    cin >> sum;
    for(int i = 1; i<=n; i++)
        cin >> coefficient[i];
}

void printSolution(){
    for(int i = 1; i<=n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Try(int pos){
    for(int v = 0; v<=remain;v++){
        x[pos] = v;
        currentSum += v*coefficient[pos];
        remain = sum - currentSum;
        if(pos==n) {
            if(remain ==0) printSolution();
        }
        else        Try(pos+1);
        currentSum -= v*coefficient[pos];
        remain = sum - currentSum;
    }
}

int main(){
    input();
    currentSum = 0;
    remain = sum;
    Try(1);
    return 0;
}