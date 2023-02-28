#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000000

int i, n;
char a, b;
char Fibonacci[MAX];
int lengk1, lengk2;

void input(){
    cout << "Enter first char: ";
    cin >> a;
    cout << "Enter second char: ";
    cin >> b;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter index: ";
    cin >> i;
}

int findFibonacciTerm(int k){
    if(Fibonacci[k] != 0)   return Fibonacci[k];
    else{
        Fibonacci[k] = findFibonacciTerm(k-2) + findFibonacciTerm(k-1);
        return Fibonacci[k];
    } 
}

char fibonacci(int n, int i){
    if(n==1)    return a;
    if(n==2)    return b;
    else{
        if(lengk2>=i){
            return fibonacci(n-2,i);
        }else{
            return fibonacci(n-1,i-findFibonacciTerm(n-2));
        }
    }
}
int main(){
    lengk1 = 1;
    lengk2 = 1;
    input();
    cout << fibonacci(n,i);
    return 0;
}