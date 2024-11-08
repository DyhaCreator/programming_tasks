#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a = {};
    ll num = 1;
    while (num <= n) {
        num *= 10;
        num++;
        ll st = 1;
        while (num * st <= n) {
            a.push_back(num * st);
            st *= 10;
        }
    }
    sort(a.rbegin(), a.rend());
    for (auto &x : a)
        cout << x << endl;
    vector<vector<ll>> dp(a.size() + 1, vector<ll>(10));
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 0; j < 10; j++) {
            ll num = a[i - 1] * j;
            ll mindp = -INF;
            for (int y = 0; y < i; y++) {
                for (int x = 0; x < 10; x++) {
                    if (abs(mindp - n) > abs(num + dp[y][x] - n)) {
                        mindp = num + dp[y][x];
                    }
                }
            }
            dp[i][j] = mindp;
        }
    }
    for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    int find = 0;
    for (auto &x : dp)
        for (auto &y : x)
            if (y == n) find = 1;
    if (find) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}