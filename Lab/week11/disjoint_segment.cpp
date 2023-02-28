#include<iostream>
#include<tuple>
#include<algorithm>
#define MAX 100000
using namespace std;

int n;
pair<int,int> a[MAX];

bool cmp (pair<int, int> a, pair<int,int> b){
    return a.second < b.second;
}

void input(){
    // cout << "Enter number of segment: ";
    cin >> n;
    for(int i = 1; i<=n; i++){
        // cout << "Enter 2 point of the " << i << " segment: ";
        cin >> a[i].first >> a[i].second;
    }
}

void solve(){
    int res = 0;
    int last = -1;
    sort(a+1,a+n+1,cmp);
    for(int i=1; i<=n; i++){
        if(a[i].first > last){
            res++;
            last = a[i].second;
        }
    }
    cout << res << endl;
}

int main(){
    input();
    solve();
    return 0;
}