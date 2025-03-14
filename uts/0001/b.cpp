#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int root = -1;
    vector<vector<int>> g(n);
    vector<int> pred(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        if (i != x) {
            g[x].push_back(i);
            pred[i] = x;
        } else {
            root = i;
        }
    }
    vector<int> p(n);
    for (auto &x : p)
        cin >> x;
    for (auto &x : p) x--;
    if (p[0] != root) {
        cout << -1 << endl;
        return;
    }
    vector<int> w(n, -1);
    vector<int> sum(n, 0);
    w[root] = 0;
    for (int i = 1; i < n; i++) {
        if (w[pred[p[i]]] == -1) {
            cout << -1 << endl;
            return;
        }
        w[p[i]] = i - sum[pred[p[i]]];
        sum[p[i]] = sum[pred[p[i]]] + w[p[i]];
    }
    for (auto &x : w)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}