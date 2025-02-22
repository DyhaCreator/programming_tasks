#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    set<int> st;
    map<int, int> mp;
    for (auto &x : a) {
        st.insert(x);
        mp[x]++;
    }
    vector<int> b = {};
    for (auto &x : st)
        b.push_back(mp[x]);
    sort(b.begin(), b.end());
    int m = b.size();
    vector<int> pref(m + 1);
    for (int i = 0; i < m; i++)
        pref[i + 1] = pref[i] + b[i];
    int ans = INF;
    for (int i = 0; i < m; i++) {
        // cout << pref[i] - pref[0] << " " << pref[m] - pref[i + 1] - b[i] * (m - i - 1) << endl;
        ans = min(ans, pref[i] - pref[0] + pref[m] - pref[i + 1] - b[i] * (m - i - 1));
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}