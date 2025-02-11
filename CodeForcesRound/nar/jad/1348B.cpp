#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    set<int> st;
    for (auto &x : a)
        st.insert(x);
    if (st.size() > k) {
        cout << -1 << endl;
        return;
    }
    vector<int> b = {};
    for (auto &x : st)
        b.push_back(x);
    while (b.size() < k)
        b.push_back(*st.rbegin());
    cout << n * k << endl;
    for (auto &x : a) {
        for (auto &y : b)
            cout << y << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}