#include<bits/stdc++.h>
using namespace std;
#define N 100
int n;
int visited[N];
int c[N][N];
int x[N];   //x[i] = j means the ith city is visited before the jth city
int f, f_best;
int xopt[N];

void updateBest(){
    if(f+c[x[n]][x[1]]<f_best){
		f_best = f+c[x[n]][x[1]];
        for(int j = 1; j<=n;j++)
            xopt[j]=x[j];
	}
}

int cMin(){
    int cmin = c[1][1];
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=n;j++)
            cmin = min(cmin,c[i][j]);
    }
    return cmin;
}

void Try(int k){
    for(int y=1; y<=n; y++){
        if(visited[y]==1)   continue;
        x[k]=y;
        visited[y] = 1;
        f += c[x[k-1]][x[k]];//update the distance
		if(k==n) updateBest();
		else Try(k+1);
        visited[y]=0;
        f -= c[x[k-1]][x[k]];
    }
}

void input(){
    cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
            cin >> c[i][j];
	}
}

int main(){
    input();
    clock_t start, end;
    double time_used = 0; 	//Khai bao them bien time_used de tinh thoi gian chay 
    f = 0;
    f_best = __INT_MAX__;
    for(int y = 0; y<=n;y++)
        visited[y] = 0;
    x[1] = 1;
    visited[1] = 1;
    start = clock();
    Try(2);
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;		//CLOCK_PER_SEC la 1 tich tac trong 1 giay
    if(f_best < __INT_MAX__){
        cout << endl << "Solution: " << endl;
        cout << "Total distance: " << f_best << endl;
        for(int i = 1; i<=n;i++)
            cout  << xopt[i]<< "-->";
        cout << xopt[1] << endl;
    }

    cout << "Time: " << time_used << "s" << endl;
    return 0;
}
