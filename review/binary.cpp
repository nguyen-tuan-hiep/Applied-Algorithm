#include<bits/stdc++.h>
using namespace std;

int n;
int x[100000];

void input(){
    cin >> n;
}

int check(int v, int k){
    //if(v + x[k-1] ==0) return 0;  // khong co 2 so 0 lien tiep
    //if(v==1 && x[k-1]==1) return 0; // khong co 2 so 1 lien tiep
    return 1;
}

void printSolution(){
    for(int i = 1; i<=n;i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void Try(int k){
    for(int v = 0; v<=1; v++){
        if(check(v,k)){
            x[k] = v;
            if(k==n){
                printSolution();
            }
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