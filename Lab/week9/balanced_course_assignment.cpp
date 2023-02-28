#include<bits/stdc++.h>

using namespace std ;

#define N 50
vector <int> T[N];
int m,n ;
bool conflict[N][N] ;
int x[N];
int load[N];
int res;

 void input(){
    cin >>m>> n;
    for(int t=1;t<=m;++t){
        int k; cin >>k ;
        for (int j=1;j<=k;++j){
            int c; cin >> c ;T[c].push_back(t);
        }
    }
    int K ;
    for (int i=1; i<=n ;++i){
        for (int j=1;j<=n;++j){
            conflict[i][j]=false;
        }
    }
    cin >> K ;
    for ( int k=1; k<=K;++k){
        int i,j; cin >>i>> j ;
        conflict[i][j]=true; conflict[j][i]= true;
    }
 }

 bool check(int t ,int k){
    for(int i=1;i<=k-1;++i){
        if(conflict[i][k]&& x[i]==t) return false;
    }
    return true;
}

void solution(){
    int maxLoad = 0 ;
    for ( int t=1; t<=m;++t){
        maxLoad= max(maxLoad,load[t]);
    }
    if(maxLoad<res) res= maxLoad;
}

void Try(int k){
    for( int i=0;i<T[k].size();++i){
        int t=T[k][i];
        if(check(t,k)){
            x[k]=t;
            load[t]+=1 ;
            if(k==n) solution();
            else{
                if(load[t]<res)
                    Try(k+1);
            }
            load[t]-= 1;
        }
    }
}

int main(){
    input();
    for( int t=1; t<=m;++t) load[t]=0;
    res=1e9 ;
    Try(1);
    cout << res;
    return 0 ;
}