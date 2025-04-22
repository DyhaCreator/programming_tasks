#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    for (auto &x : a)
        cin >> x;
    for (auto &x : a)
        st.insert(x);
    cout << st.size() << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}