#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : a)
        x = k - x % k;
    set<ll> st;
    map<ll, ll> mp;
    for (auto &x : a) {
        if (x != k) {
            st.insert(x);
            mp[x]++;
        }
    }
    if (st.size() == 0) {
        cout << 0 << endl;
        return;
    }
    ll mx = 0;
    for (auto &x : st)
        if (mp[mx] <= mp[x]) mx = x;
    cout << k * (mp[mx] - 1) + mx + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}