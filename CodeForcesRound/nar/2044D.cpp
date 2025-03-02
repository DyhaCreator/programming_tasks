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
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    set<int> st;
    for (auto &x : a)
        st.insert(x);
    vector<int> c = {};
    for (auto &x : st)
        c.push_back(x);
    set<pair<int, int>> s;
    for (auto &x : c)
        s.insert({0, x});
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] >= i / c.size() + 1) {
            int d = s.begin()->S;
            s.erase(*s.begin());
            cnt[d]++;
            s.insert({cnt[d], d});
            cout << d << " ";
        } else {
            s.erase({cnt[a[i]], a[i]});
            cnt[a[i]]++;
            s.insert({cnt[a[i]], a[i]});
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}