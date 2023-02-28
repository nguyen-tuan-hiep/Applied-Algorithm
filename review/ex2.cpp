#include<bits/stdc++.h>
using namespace std;
int n;
int p[100000];
string s;
stack<int> st;
queue<int> q;

void input(){
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> p[i];
    }
    cin >> s;

}

void solve(){
    for(int i=n; i>=1; i--){
        st.push(p[i]);
    }
    for(int i = 0; i<s.size();i++){
        if(s[i] == 'C'){
            q.push(st.top());
            st.pop();
        }
        else if(s[i] == 'H'){
            st.push(q.front());
            q.pop();
        }
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){
    input();
    solve();
    return 0;
}