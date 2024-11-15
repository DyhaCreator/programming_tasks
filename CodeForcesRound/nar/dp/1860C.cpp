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
    int start = INF;
    int minS = INF;
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        if (a[i] > start && a[i] < minS) {
            dp[i + 1]++;
            minS = a[i];
        }
        if (a[i] < start)
            start = a[i];
    }
    cout << dp[n] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}