#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;
// PARENTHESES
int main(){
    cin.tie(nullptr) -> ios_base::sync_with_stdio(false);
    string s{};
    cin >> s;
    int x{};
    stack<char> st{};
    bool isCorrect{false};
    for(x = 0; x < s.size(); ++x){
        char i{s[x]};
        if (i == '(' or i == '[' or i == '{'){
            st.push(i);
        }
        else{
            if (st.empty()){
                break;
            }
            else if(i == ')' and st.top() == '(')    st.pop();
            else if(i == ']' and st.top() == '[')    st.pop();
            else if(i == '}' and st.top() == '{')    st.pop();
            else    break;
        }
    }
    if (x == s.size() and st.empty())   isCorrect = true;
    cout << isCorrect;
    return 0;
}