#include<bits/stdc++.h>

int n;
int a[100];

void printSolution(){
    for(int i = 1; i<=n;i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

bool check(int y, int k){
    for(int i = 1; i<=k-1; i++)
        if(a[i]==y) return false;
    return true;
}

void Try(int k){
    for(int y = 1; y<=n; y++){
        if(check(y,k)){
            a[k]=y;
            if(k==n)    printSolution();
            else Try(k+1);
        }
    }
}

int main(){
    std::cout << "Enter n: ";
    std::cin >> n;
    Try(1);
}