#include<bits/stdc++.h>
using namespace std;
int n, M, N;            // n: number of elementsm, M: target sum, N: current sum
int coefficient[100];
int x[100];
int cnt{0};
void printSolution(){
    for(int i = 1;i<=n;i++)
        cout << x[i] << " ";
    cout << endl;
}

int check(int j, int k){
    if(k==n) return N+j*coefficient[k]==M;
    return 1;
}

void Try(int k){
    for(int j = 1;j<=(M-N-(n-k))/coefficient[k];j++){
        if(check(j,k)){
            x[k]=j;
            N+=j*coefficient[k];
            if(k==n) {
                //printSolution();
                ++cnt;
            }
            else Try(k+1);
            N-=j*coefficient[k];
        }
    }
}

int main(){
    cin >> n >> M;
    for(int i=1;i<=n;++i){
        cin >> coefficient[i];
    }
    Try(1);
    cout << cnt;
    return 0;
}