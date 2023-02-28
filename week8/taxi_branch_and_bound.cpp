#include<bits/stdc++.h>
#define N 50
using namespace std;

int c[N][N];
int n;
int x[N];
int xopt[N];
int visited[N];// visited[1] indicates that v is visited, visited[0] otherwise
int f;//partial distance (accumulated during the search)
int f_best;//best objective value (min distance found so far)
void input(){
	scanf("%d",&n);
	for(int i=0;i<=2*n;i++){
		for(int j=0;j<=2*n;j++)
			scanf("%d",&c[i][j]);
	}
}

int cMin(){
    int cmin = c[1][1];
    for(int i = 0; i<=2*n;i++){
        for(int j = 0; j<=2*n;j++)
            cmin = min(cmin,c[i][j]);
    }
    return cmin;
}

void Try(int k){
	for(int v=1;v<=n;v++){
		if(visited[v]==1)   continue;
        x[k] =v;
        visited[v]=1;
        if(k==1) f=c[0][x[1]]+c[x[1]][x[1]+n];
        else f += c[x[k-1]+n][x[k]]+c[x[k]][x[k]+n];//update the distance
        if(k==n) {
            int g = f+c[x[n]+n][0];
            if(g<f_best) {
                f_best=g;
                for (int j=1 ; j<=n;++j) xopt[j]= x[j];
            }
        }
        else if(f+(2*(n-k)+1)*cMin()<f_best) {
            Try(k+1);
        }
        visited[v]=0;
        if(k==1) f=0;
        else f -= c[x[k-1]+n][x[k]]+c[x[k]][x[k]+n];
	}
}

int main(){
	input();
	f=0;
	f_best = INT_MAX;
	for(int v =1; v<=n;v++)	visited[v]=0;
	x[0]=0;
	visited[0]=1;
	Try(1);

	if(f_best<INT_MAX) {
        printf("solution: \n");
        cout <<"f_best: "<< f_best << endl ;
		for(int i=0;i<=n;i++)	printf("%d -->",xopt[i]);
		cout<< xopt[0] << endl;
	}else
	    cout<< "No solution";
	return 0;
}