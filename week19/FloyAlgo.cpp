#include<bits/stdc++.h>
#define V 5
#define INF 99999
int D[V][V]  = { 	{0, 3, 8, INF, -4},
                	{INF, 0, INF, 1, 7},
                	{INF, 4, 0, INF, INF},
                	{2, INF, -5, 0, INF},
                    {INF, INF, INF, 6, 0}
            	};
int P[V][V];

void floydWarshall(int D[V][V]){
    for (int k = 0; k < V; k++){
    	// printf("------------------------------------\nD%d:\n",k+1);
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if (D[i][k] + D[k][j] < D[i][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k+1;
                }
				// if (D[i][j] == INF)	printf("%7s/0", "INF");
            	// else				printf ("%7d/%d", D[i][j], P[i][j]);
            }
            // printf("\n");
        }
        // printf("\n");
    }
}

void printD(){
    for(int i=0;i<V;i++){
    	for (int j = 0; j < V; j++){
        	if (D[i][j] == INF)	printf("%6s", "INF");
            else				printf ("%6d", D[i][j]);
        }
        printf("\n");
	}
}

int main(){
    floydWarshall(D);
    printD();
    return 0;
}