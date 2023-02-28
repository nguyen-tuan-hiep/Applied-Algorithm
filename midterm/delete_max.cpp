#include<bits/stdc++.h>

using namespace std;

int n;
string command;
int a[100000];
priority_queue<int> pq;


int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(NULL);
    // cout.tie(NULL);
    fflush(stdin);
    freopen("1-input.txt", "r", stdin);
    scanf("%d",&n);
    for(int i = 1; i<=n; i++){
        scanf("%d",&a[i]);
        pq.push(a[i]);
    }
    
    do {
        cin >> command;
        if (command == "insert") {
            int x;
            // fflush(stdin);
            scanf("%d",&x);
            pq.push(x);
            // cout << pq.top() << endl;
        }
        else if (command == "delete-max") {
            cout << pq.top() << endl;
            pq.pop();
        }

    }
    while (command!="*");
    return 0;
}
