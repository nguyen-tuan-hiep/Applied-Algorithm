#include<bits/stdc++.h>
using namespace std;

int S;
int mem[1000][1000];
int d[100];

int opt(int i, int S){
    if(i<0 || S < 0) return 99999999;
    if(S==0){
        mem[i][S]=0;
        return 0;
    }    
    if(mem[i][S]!=-1)   return mem[i][S];
    int res = min(opt(i-1,S), 1+ opt(i,S-d[i]));
    mem[i][S] = res;
    return res;
}
void trace(int i, int S){
    if(i<0 || S<=0) return;
    if(mem[i][S]==mem[i-1][S])   trace(i-1,S);
    else{
        cout << d[i] << " ";
        trace(i,S-d[i]);
    }
    
}

int main(){
    memset(mem,-1,sizeof(mem));
    int n,X;
    cout << "Enter # of money type: ";
    cin >> n;
    cout << "Enter value of each money: ";
    for(int i = 0; i<n;i++)
        cin >> d[i];
    cout << "Enter X: ";
    cin >> X;
    int res = opt(n-1,X);
    cout << res << endl;
    trace(n-1,X);
    cout << endl;
    for(int i = n-1, k=0; k<=res;){
        if(mem[i][X] == 1+mem[i][X-d[i]]){
            cout << d[i] << " ";
            X -= d[i];
            k++;
        }
        else  i--;

    }
}