#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct tr{
    int a, b, c;
    tr() {}
    tr(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    map<pair<int, int>, pair<set<ll>, map<ll, ll>>> mp;
    map<pair<int, int>, ll> col;
    set<pair<int, int>> st;
    for (int i = 0; i < n - 2; i++) {
        mp[{a[i], a[i + 1]}].first.insert(a[i + 2]);
        mp[{a[i], a[i + 1]}].second[a[i + 2]]++;
        st.insert({a[i], a[i + 1]});
        col[{a[i], a[i + 1]}]++;
    }
    ll ans = 0;
    for (auto &x : st) {
        ans += col[x] * (col[x] - 1) / 2;
        for (auto &y : mp[x].first)
            ans -= mp[x].second[y] * (mp[x].second[y] - 1) / 2;
    }
    // cout << ans << endl;
    mp.clear();
    col.clear();
    st.clear();
    for (int i = 0; i < n - 2; i++) {
        mp[{a[i], a[i + 2]}].first.insert(a[i + 1]);
        mp[{a[i], a[i + 2]}].second[a[i + 1]]++;
        st.insert({a[i], a[i + 2]});
        col[{a[i], a[i + 2]}]++;
    }
    for (auto &x : st) {
        ans += col[x] * (col[x] - 1) / 2;
        for (auto &y : mp[x].first)
            ans -= mp[x].second[y] * (mp[x].second[y] - 1) / 2;
    }
    // cout << ans << endl;
    mp.clear();
    col.clear();
    st.clear();
    for (int i = 0; i < n - 2; i++) {
        mp[{a[i + 1], a[i + 2]}].first.insert(a[i]);
        mp[{a[i + 1], a[i + 2]}].second[a[i]]++;
        st.insert({a[i + 1], a[i + 2]});
        col[{a[i + 1], a[i + 2]}]++;
    }
    for (auto &x : st) {
        ans += col[x] * (col[x] - 1) / 2;
        for (auto &y : mp[x].first)
            ans -= mp[x].second[y] * (mp[x].second[y] - 1) / 2;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}