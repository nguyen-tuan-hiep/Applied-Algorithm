#include<iostream>
#include<stack>
using namespace std;

void brute_force(int price[], int N, int span[]){
    for(int i = 0; i< N;i++){
        span[i] = 0;
        for(int j = i-1; j>=0; j--){
            if(price[j] <= price[i]){
                span[i] ++;
            }else{
                break;
            }
        }
    }
    
    for(int i = 0; i< N;i++){
        cout << span[i] << " ";
    }
}

void solve(int price[], int N, int span[]){
    stack<int> s;
    span[0] = 0;
	s.push(0);
	for(int i = 1; i < N; i++){
		while(!s.empty() && price[i] >= price[s.top()])
			s.pop();
		if(s.empty())	span[i] = i;
		else span[i] = i - s.top() - 1;
		s.push(i);
	}
	for(int i = 0; i<N;i++){
		cout << span[i] << " ";
	}
}

int main(){
    int N;
    cin >> N;
    int price[N];
    for(int i = 0; i< N; i++){
        cin >> price[i];
    }
	// price[] = {100, 60, 70, 65, 80, 85};
	int span[N];
	cout << "Using bruteforce: ";
    brute_force(price, N, span);
    cout << endl << "Using stack: ";
    solve(price, N, span);
}