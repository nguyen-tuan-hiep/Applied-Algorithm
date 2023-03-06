#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;

stack<int> st;

int main(){
    cin.tie(nullptr) -> ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    string cmd;
    do{
        cin >> cmd;
        if(cmd == "PUSH"){
            int x;
            cin >> x;
            st.push(x);
        }
        else if(cmd == "POP"){
            if(st.empty()){
                cout << "NULL" << '\n';
                continue;
            }
            cout << st.top() << '\n';
            st.pop();
        }
    }while(cmd != "#");
    return 0;
}