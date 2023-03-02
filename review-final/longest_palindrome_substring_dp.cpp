// https://www.techiedelight.com/longest-palindromic-substring-non-dp-space-optimized-solution/
#include<bits/stdc++.h>
using namespace std;

string s;
void input(){
    cin >> s;
}

int solve(){
    int n = s.size();
    int start = 0, end = 0;
    for(int i = 0; i < n; i++){
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r]){
            if(r - l > end - start){
                start = l;
                end = r;
            }
            l--;
            r++;
        }
        l = i, r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r]){
            if(r - l > end - start){
                start = l;
                end = r;
            }
            l--;
            r++;
        }
    }
    return end - start + 1;
}

int main(){
    input();
    cout << solve();
    return 0;
}