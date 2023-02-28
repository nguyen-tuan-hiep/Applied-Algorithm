#include<bits/stdc++.h>
using namespace std;

int n;
int a[100], cnt = 0;

void printSolution(){
    cnt ++ ;
    for(int i = 1; i<=n;i++)
        cout << "(" << i << ", " << a[i] << ") ";
    cout << endl;
}

bool check(int y, int k){
    for(int i = 1; i<=k-1;i++){
        if(y==a[i]||abs(k-i) == abs(y-a[i]))    return false;
    }
    return true;
}

void Try(int k){
    for(int y = 1;y<=n;y++){
        if(check(y,k)){
            a[k] = y;
            if(k==n)    printSolution();
            else Try(k+1);
        }
    }
}

int main(){
    cout << "Enter n: ";
    cin >> n;
    Try(1);
    if(cnt == 0)
        cout << "Problem does not have solution";
}