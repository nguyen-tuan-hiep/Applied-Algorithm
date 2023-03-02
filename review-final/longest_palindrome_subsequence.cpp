// https://www.techiedelight.com/longest-palindromic-subsequence-using-dynamic-programming/
#include<bits/stdc++.h>
using namespace std;
string s;
void input(){
    cin >> s;
}

int solve(int start, int end){
    if(start > end) return 0;
    if(start == end) return 1;
    if(s[start] == s[end]) return 2 + solve(start + 1, end - 1);
    return max(solve(start + 1, end), solve(start, end - 1));
}

int main(){
    input();
    cout << solve(0, s.size() - 1);
    return 0;
}