#include<bits/stdc++.h>
using namespace std;

int main(){
    int numTest, num1, num2;
    cout << "Start: " << endl;
    cin >> numTest;
    for(int count = 0; count<numTest; count++){
        cin>>num1>>num2;
        map<int,int> a; // dung de luu so lan xuat hien cua cac phan tu
        int x;
        for(int i=0; i<num1; i++){
            cin>>x;
            a[x]++;
        }
        for(int i=0; i<num2; i++){
            cin>>x;
            a[x]--;
        }
        int result=0;
        for(map<int,int>::iterator it = a.begin(); it!=a.end();it++){
            result += abs(it->second);  //value of a
        }
        cout<<result;
    }
}
