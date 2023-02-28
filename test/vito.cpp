#include<bits/stdc++.h>
using namespace std;

int bruteforce(int r, int s[]){
    int minDistance = 99999;
    for(int i = 0; i<r;i++){
        int distance = 0;
        for(int j = 0; j<r;j++){
            distance += abs(s[i]-s[j]);
        }
        if(minDistance > distance)  
            minDistance = distance;
    }
    return minDistance;
}

int median(int r, int s[]){
    int minDistance;
    sort(s, s+r);
    int median = s[r/2];
    for(int i = 0; i<r;i++){
        minDistance += abs(median - s[i]);
    }
    return minDistance;
}


int main(){
    cout << "Nhap so test case: ";
    int testCase;
    cin >> testCase;
    for(int i = 0; i< testCase; i++){
        int r;
        cout << "Nhap so relative: ";
        cin >> r;
        int s[r];
        for(int j = 0; j < r; j++){
            cout << "Nhap addrees[" << j+1 << "]: ";
            cin >> s[j];
        }
        cout << median(r, s) << endl;
        cout << bruteforce(r, s) << endl;
    }
}