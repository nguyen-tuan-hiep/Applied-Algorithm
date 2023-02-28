#include<stdio.h>
#define N 50
int c[N][N];
int n;
int x[N];
int visited[N];// visited[1] indicates that v is visited, visited[0] otherwise
int f;//partial distance (accumulated during the search)
int f_best;//best objective value (min distance found so far)
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
}
void updateBest(){ 
	if(f+c[x[n]][x[1]]<f_best){
		f_best = f+c[x[n]][x[1]];
		printf("update best solution: ");
		for(int i=1;i<=n;i++)	printf("%d ",x[i]);
		printf("update f_best = %d\n", f_best);
	}
}
void Try(int k){
	for(int v=1;v<=n;v++){
		if(visited[v]==0){
			x[k] =v;
			visited[v]=1;//update v as visited
			f = f+ c[x[k-1]][x[k]];//update the distance
			if(k==n) updateBest();
			else{
				Try(k+1);
			}
			visited[v]=0;//recover
			f = f- c[x[k-1]][x[k]];//recover
		}
	}	
}

int main(){
	freopen("tsp.txt","r", stdin);
	input();
	f=0;
	f_best = 10000000;
	for(int v =1; v<=n;v++)	visited[v]=0;
	x[1]=1;
	visited[1]=1;
	Try(2);
	return 0;
}









