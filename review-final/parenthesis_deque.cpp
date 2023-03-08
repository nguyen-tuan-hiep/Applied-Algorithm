#include<bits/stdc++.h>
using namespace std;

deque<char> dq;
string s;

void input(){
    cin >> s;
}

void solve(){
    for(int i = 0; i<s.size(); ++i){
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            dq.push_back(s[i]);
        else if(s[i] == ')' || dq.front() == s[i]) dq.pop_front();
        else if(s[i] == ']' || dq.front() == s[i]) dq.pop_front();
        else if(s[i] == '}' || dq.front() == s[i]) dq.pop_front();
    }
    if(dq.empty())  cout << 1 << endl;
    else cout << 0 << endl;
}

int main(){
    input();
    solve();
    return 0;
}