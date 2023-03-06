// input string s, a, b
// output string s with all a replaced by b

#include <iostream>
#include <string>
using namespace std;

string s;
string a, b;

void input(){
    getline(cin, a);
    getline(cin, b);
    getline(cin, s);
}

void solve(){
    int pos = s.find(a);
    while(pos != string::npos){
        s.replace(pos, a.length(), b);
        pos = s.find(a, pos + b.length());
    }
    cout << s << endl;
}

int main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    input();
    solve();
    return 0;
}