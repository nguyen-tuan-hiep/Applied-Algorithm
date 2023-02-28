#include<bits/stdc++.h>
using namespace std;


void bruteForce(int size,int s[]){
    int min_Distance=99999999;
    for (int i=0;i<size;++i){
        int distance=0;
        for (int j=0;j<size;++j){
            distance+=abs(s[i]-s[j]);
        }
    if(min_Distance>distance) min_Distance =distance;
    }
    cout << min_Distance << "\n";
};

void median (int size, int s[]){
    sort(s,s+size);
    int min_Distance= 0 ,median = s[size/2] ;
    for (int i=0;i<size;++i){
        min_Distance+= abs(s[i]-median);
    }
    cout << min_Distance;
}

int main(){
    int i=0;
    int numTestCase;
    int s[1000],size,count=0;
    cout<< "Nhap so test case:";
    cin >> numTestCase;
    while (count != numTestCase){
        cout << "Nhap so nha" ;
        cin >> size;
        for (int i=0;i< size;++i){
            cout<< "Nhap phan tu thu " << i+1 <<" :";
            cin >> s[i];
        }
        bruteForce(size,s);
        median(size,s);
        count++;
    }

}