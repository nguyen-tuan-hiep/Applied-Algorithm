//codechef.com/problems/COVID19

#include <iostream>
using namespace std;

void solve(int N, int X[]){
    int caMin = N, caMax = 1;
    int count = 1;
    for(int i = 1; i<N; i++){
        if(abs(X[i] - X[i-1]) <= 2){
            count ++;
        }

        else{
            caMin = min(caMin, count);
            caMax = max(caMax, count);
            count = 1;
        }
    }
    caMin = min(caMin, count);
    caMax = max(caMax, count);

    cout << caMin << " " << caMax << endl;
}

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--){
	    int N;
	    cin >> N;
	    int X[N];
	    for(int j = 0; j <N;j++ ){
	        cin >> X[j];
	    }
	    solve(N,X);
	}
	return 0;
}
