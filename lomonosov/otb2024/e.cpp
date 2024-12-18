#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (auto &x : a) for (auto &y : x) cin >> y;
    vector<vector<ll>> pref(n + 1, vector<ll>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + a[i][j];
        }
    }
    set<ll> sums;
    map<ll, ll> count;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int y = 0; y < i; y++) {
                for (int x = 0; x < j; x++) {
                    ll sum = pref[i][j] - pref[i][x] - pref[y][j] + pref[y][x];
                    // cout << sum << " ";
                    for (auto &x : sums) {
                        if (x + sum > r) break;
                        if (x + sum >= l) ans += count[x];
                    }
                    sums.insert(sum);
                    count[sum]++;
                }
                // cout << endl;
            }
            // cout << endl;
        }
    }
    cout << ans << endl;
    return 0;
}