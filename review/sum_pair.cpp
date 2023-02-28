//https://openerp.dailyopt.ai/programming-contest/student-view-contest-problem-detail/APPLIED_ALGORITHM_2022_2023_1/SUM_PAIR_EQUAL_M

#include<bits/stdc++.h>
using namespace std;

int n, M;
int a[10000000];
int cnt=0;

void input(){
    cin >> n >> M;
    for(int i = 1; i<=n; i++)
        cin >> a[i];
}

void solve(){
    map<int, int> m; // m = {a[i], i}
    for(int i = 1; i<=n; i++){
        int remain = M - a[i];
        if(m.count(remain)==0)  // check xem remain co trong key cua map m hay khong
            m.insert({a[i],i});
        else    cnt++;
    }
    cout << cnt << endl;
}

int main(){
    input();
    solve();
    return 0;
}