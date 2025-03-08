#include <bits/stdc++.h>
#define F first
#define S second
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<string, string>> a(n);
    for (auto &[x, y] : a)
        cin >> x >> y;
    set<string> st;
    for (auto &[x, y] : a)
        st.insert(x);
    vector<string> ss = {};
    for (auto &x : st)
        ss.push_back(x);
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}