#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs_sq(int v, vector<vector<pair<ll, ll>>> &g, vector<int> &used,
    vector<vector<pair<ll, ll>>> &gsq, vector<pair<ll, ll>> &gsqn) {
    // cout << v << endl;
    used[v] = 1;
    for (auto &x : g[v]) {
        if (used[x.F] == 0) {
            gsq[v].push_back(x);
            gsqn[x.F] = {v, x.S};
            dfs_sq(x.F, g, used, gsq, gsqn);
        }
    }
}

void dfs_pred(int v, vector<vector<pair<ll, ll>>> &g, vector<int> &used,
    vector<vector<int>> &pred) {
    used[v] = 1;
    for (auto &x : g[v]) {
        if (used[x.F] == 0) {
            pred[x.F] = pred[v];
            pred[x.F].push_back(v);
            dfs_pred(x.F, g, used, pred);
        }
    }
}

bool fnd(vector<int> &a, int b) {
    int l = 0;
    int r = a.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] < b) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (a[r] == b)
        return 1;
    return 0;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<pair<ll, ll>>> g(n);
    for (int i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vector<vector<pair<ll, ll>>> gsq(n);
    vector<pair<ll, ll>> gsqn(n);
    vector<int> used(n, 0);
    gsqn[0] = {-1, -1};
    dfs_sq(0, g, used, gsq, gsqn);
    used = vector<int>(n, 0);
    vector<vector<int>> pred(n);
    dfs_pred(0, g, used, pred);
    for (auto &x : pred)
        sort(x.begin(), x.end());
    for (int i = 0; i < q; i++) {
        ll a, b, d;
        cin >> a >> b >> d;
        a--;b--;
        vector<ll> w = {};
        int v = a;
        while (!fnd(pred[b], v)) {
            w.push_back(gsqn[v].S);
            v = gsqn[v].F;
        }
        vector<ll> w2 = {};
        int u = b;
        while (v != u) {
            w2.push_back(gsqn[u].S);
            u = gsqn[u].F;
        }
        reverse(w2.begin(), w2.end());
        for (auto &x : w2)
            w.push_back(x);
        /*for (auto &x : w)
            cout << x << " ";
        cout << endl;*/
        vector<ll> l(w.size() + 1, 0);
        vector<ll> r(w.size() + 1, 0);
        for (int i = 0; i < w.size(); i++)
            l[i + 1] = l[i] + w[i];
        for (int i = w.size() - 1; i >= 0; i--)
            r[i] = r[i + 1] + w[i];
        /*for (auto &x : l)
            cout << x << ' ';
        cout << endl;
        for (auto &x : r)
            cout << x << " ";
        cout << endl;*/
        int ans = 0;
        if (l[w.size()] == d)
            ans++;
        for (int i = 1; i < w.size(); i++) {
            // cout << l[i] * r[i] << endl;
            if (l[i] * r[i] == d)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}