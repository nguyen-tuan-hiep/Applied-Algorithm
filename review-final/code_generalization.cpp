// https://openerp.dailyopt.ai/programming-contest/student-view-contest-problem-detail/APPLIED_ALGORITHM_2022_2023_1/CODE_GEN_STD_DBMS

#include<bits/stdc++.h>
using namespace std;

int n, l;

void input(){
    cin >> n >> l;
}

void solve(string s){
    while(s.length() < l) s = "0" + s;
    cout << s << '\n';
}

int main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    cout.tie(nullptr);
    input();
        while(n--){
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}