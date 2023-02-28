#include<bits/stdc++.h>
using namespace std;
string a,b;
int mem[1000][1000];

int lcs(int i, int j){
    if(i==-1||j==-1)    return 0;
    if(mem[i][j] != -1)  return mem[i][j];
    if(a[i]==b[j])  mem[i][j] = lcs(i-1,j-1)+1;
    else mem[i][j] = max(lcs(i,j-1), lcs(i-1,j));
    return mem[i][j];
}

void trace(int i, int j){
    if(i==-1 || j==-1)  return;
    if(a[i]==b[j] && mem[i][j] == mem[i-1][j-1]+1){
        trace(i-1,j-1);
        cout << a[i];
        return;
    }
    if(mem[i][j] == mem[i][j-1]){
        trace(i,j-1);
        return;
    }
    if(mem[i][j] == mem[i-1][j]){
        trace(i-1,j);
        return;
    }
   
}

int main(){
    memset(mem,-1,sizeof(mem));
    cout << "Enter string A: ";
    cin >> a;
    cout << "Enter string B: ";
    cin >> b;
    int res = lcs(a.length()-1,b.length()-1);
    cout << "Longest common subsequence: ";
    trace(a.length()-1,b.length()-1);
    cout << endl << "Longest length = " << res << endl;
}