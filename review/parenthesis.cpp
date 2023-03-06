#include<bits/stdc++.h>
using namespace std;

string s;
stack<char> st;

void input(){
    cin >> s;
}

void solve(){
    for(int i = 0; i<s.size(); i++){
        if(s[i]=='[' || s[i]=='(' || s[i]=='{'){
            st.push(s[i]);            
        }
        else{
            if(st.empty()){
                cout << 0 << endl;
                return;
            }
            char c = st.top();
            st.pop();
            if(s[i]==']' && c=='['){
                cout << 1 << endl;
                return;
            }
            if(s[i]==')' && c=='('){
                cout << 1 << endl;
                return;
            }
            if(s[i]=='}' && c=='{'){
                cout << 1 << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}

int main(){
    input();
    solve();
    return 0;
}