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
    vector<pair<ll, ll>> dp(n + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            dp[i + 1] = {dp[i].first + 1, dp[i].second};
        } else {
            dp[i + 1] = {dp[i].second, dp[i].first + 1};
        }
    }

    ll ans1 = 0;
    ll ans2 = 0;
    for (auto &x : dp) {
        ans1 += x.first;
        ans2 += x.second;
    }
    cout << ans2 << " " << ans1 << endl;
    return 0;
}