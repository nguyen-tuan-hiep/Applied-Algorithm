#include<bits/stdc++.h>
using namespace std;
#define N 40

int m{0};
int n;  //passenger
int K;  //capacity of places
int c[N][N];
int X[N];    //solution representation for the route of bus
bool appear[N]; //check if the place is visited in partial solution
int load; //number of people on the bus
int f;  //total distane of the partial solution (route) (accumulated)
int f_min;
void input(){
    cin >> n >> K;
    for(int i = 0; i<=2*n; i++){
        for(int j = 0; j<= 2*n; j++){
            cin >> c[i][j];
        }
    }
}

bool check(int v, int k){
    if(appear[v]==true) return false;
    if(v<=n){
        if(appear[v+n]==true)   return false;
        if(load+1>K)    return false;
    }
    else{   //drop off point
        if(appear[v-n]==false)   return false;
    }
    return true;
}

void solution(){
    if(f + c[X[2*n]][0] < f_min){
        f_min = f + c[X[2*n]][0];
    }
}

void Try(int k){
    for(int v = 1; v<=2*n; v++){
        if(check(v,k)){
            X[k]=v; //the route goes to the point v
            if(v<=n)    load +=1;   //1 person get in
            else load -=1;  //1 person get down
            f = f + c[X[k-1]][X[k]];
            appear[v] = true;
            if(k==2*n) solution();
            else{
                Try(k+1);
            }
            if(v<=n)    load -= 1;
            else load += 1;
            f = f-c[X[k-1]][X[k]];
            appear[v] = false;
        }
    }
}

int main(){
    input();
    for(int v = 1; v <=2*n;v++) appear[v] = false;
    f = 0;
    f_min = 1e9;
    load = 0;
    Try(1);
    cout << f_min;
    return 0;
}
