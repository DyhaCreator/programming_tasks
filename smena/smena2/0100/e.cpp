#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> b(n);
    for (auto &x : b)
        cin >> x;
    vector<int> dp(n + 1, -INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int mn = i;
        for (int j = i; j > 0; j--) {
            if (a[j - 1] < a[mn - 1]) mn = j;
            dp[i] = max(dp[i], dp[j - 1] + b[mn - 1]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}