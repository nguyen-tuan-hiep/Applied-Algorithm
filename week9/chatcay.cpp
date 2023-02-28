#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int h[1000001];
int N, H, M;

int eko(){
	H = *max_element(h + 1, h + N) - 1;	//Tim do cao max - 1
	int current = 0;					//So met go hien tai
	while(current < M){
		for (int i = 1; i <= N; ++i){
			if (h[i] > H){
				h[i]--;
				current++;
			}
		}
		H--;
	}
	return H + 1;
}

int main(int argc, char const *argv[]){
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		cin >> h[i];
	H = eko();
	cout << H;
	return 0;
}