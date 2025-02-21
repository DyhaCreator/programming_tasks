#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<vector<ll>> c(n);
    for (int i = 0; i < n; i++)
        c[a[i] - 1].push_back(b[i]);
    for (auto &x : c)
        sort(x.begin(), x.end());
    ll ans = 0;
    for (auto &x : b)
        ans += x;
    for (auto &x : c) {
        vector<ll> d(x.size() + 1);
        for (int i = 0; i < x.size(); i++)
            d[i + 1] = x[i] + d[i];
        x = d;
    }
    set<pair<int, vector<ll>>> st;
    for (int i = 0; i < n; i++)
        if (c[i].size() > 1) st.insert({i, c[i]});
    /*for (auto &x : st) {
        for (auto &y : x.S)
            cout << y << " ";
        cout << endl;
    }*/
    for (int i = 1; i <= n; i++) {
        vector<pair<int, vector<ll>>> d = {};
        ll sum = 0;
        for (auto &x : st) {
            if (x.S.size() <= i) {
                d.push_back(x);
                continue;
            }
            sum += x.S[(x.S.size() - 1) % i];
        }
        for (auto &x : d) {
            ans -= x.S[x.S.size() - 1];
            st.erase(x);
        }
        cout << ans - sum << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}