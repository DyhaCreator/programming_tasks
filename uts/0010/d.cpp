#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void rec(int len, vector<pair<int, int>> &a, vector<int> &ans) {
    if (a.size() == 0) return;
    if (a.size() == 1) {
        ans[a[0].S] = len;
        return;
    }
    int mx = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[mx].F < a[i].F) mx = i;
    ans[a[mx].S] = len;
    vector<pair<int, int>> b = {};
    vector<pair<int, int>> c = {};
    for (int i = 0; i < a.size(); i++) {
        if (i < mx) {
            b.push_back(a[i]);
        } else if (i > mx) {
            c.push_back(a[i]);
        }
    }
    rec(len + 1, b, ans);
    rec(len + 1, c, ans);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++)
        b[i] = {a[i], i};
    vector<int> ans(n);
    rec(0, b, ans);
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}