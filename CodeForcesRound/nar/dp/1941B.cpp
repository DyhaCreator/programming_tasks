#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> dp(n);
    for (int i = 0; i < n - 2; i++) {
        if (a[i] < 0) {
            cout << "NO" << endl;
            return;
        }
        dp[i] = a[i];
        a[i] = 0;
        a[i + 1] -= dp[i] * 2;
        a[i + 2] -= dp[i];
    }
    if (a[n - 1] != 0 || a[n - 2] != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}