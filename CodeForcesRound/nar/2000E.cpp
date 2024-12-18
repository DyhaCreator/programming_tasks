#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<int> a(w);
    for (auto &x : a)
        cin >> x;
    vector<vector<ll>> dc(n + 1, vector<ll> (m + 1, 0));
    for (int y = 0; y <= n - k; y++) {
        for (int x = 0; x <= m - k; x++) {
            dc[y][x] += 1;
            dc[y + k][x] -= 1;
            dc[y][x + k] -= 1;
            dc[y + k][x + k] += 1;
        }
    }
    vector<vector<ll>> mp(n + 1, vector<ll> (m + 1, 0));
    set<ll> st;
    map<ll, ll> counter;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            mp[y][x] += dc[y - 1][x - 1];
            mp[y][x] += mp[y - 1][x];
            mp[y][x] += mp[y][x - 1];
            mp[y][x] -= mp[y - 1][x - 1];
            st.insert(mp[y][x]);
            counter[mp[y][x]]++;
        }
    }
    vector<ll> vc = {};
    for (auto &x : st)
        vc.push_back(x);
    reverse(vc.begin(), vc.end());
    /*for (auto &x : vc)
        cout << x << " ";
    cout << endl;
    for (auto &x : vc)
        cout << counter[x] << " ";
    cout << endl;*/
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    int index = 0;
    for (auto &x : vc) {
        ll c = counter[x];
        while (index < w && c > 0) {
            ans += a[index] * x;
            // cout << a[index] << " " << x << endl;
            index++;
            c--;
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}