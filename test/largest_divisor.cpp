#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int N;
	cin >> N;
	int result = 1;
	for(int i = 1; i<= 10;i++){
	    if(N%i==0){
	        result = max(result,i);
	    }
	}
	cout << result;
	return 0;
}

