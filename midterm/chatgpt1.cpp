#include <iostream>
#include <vector>

using namespace std;

int n, k, A, B, sum, count;
vector<int> a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    fflush(stdin);
    freopen("4-input.txt", "r", stdin);
    cin >> n >> k >> A >> B;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }


    for (int i = 1; i <= n - k + 1; i++) {
        sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += a[j];
        }
        if (sum >= A && sum <= B) {
            count++;
        }
        sum -= a[i];
        if (i + k <= n) {
            sum += a[i + k];
        }
    }
    cout << count << endl;
    return 0;

    // for (int i = 1; i <= n - k + 1; i++) {
    //     sum = 0;
    //     for (int j = i; j < i + k; j++) {
    //         sum += a[j];
    //     }
    //     if (sum >= A && sum <= B) {
    //         count++;
    //     }
    // }
    // cout << count << endl;
    // return 0;
}
