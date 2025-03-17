#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs_sq(int v, vector<vector<pair<ll, ll>>> &g, vector<int> &used,
    vector<pair<ll, ll>> &gsqn, vector<ll> &ln) {
    used[v] = 1;
    for (auto &x : g[v]) {
        if (used[x.F] == 0) {
            gsqn[x.F] = {v, x.S};
            ln[x.F] = ln[v] + 1;
            dfs_sq(x.F, g, used, gsqn, ln);
        }
    }
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
    vector<pair<ll, ll>> gsqn(n);
    vector<int> used(n, 0);
    gsqn[0] = {-1, -1};
    vector<ll> ln(n);
    dfs_sq(0, g, used, gsqn, ln);
    /*for (auto &x : gsqn)
        cout << x.F << " ";
    cout << endl;
    for (auto &x : ln)
        cout << x << " ";
    cout << endl;*/
    for (int i = 0; i < q; i++) {
        ll a, b, d;
        cin >> a >> b >> d;
        a--;b--;
        vector<ll> w1 = {};
        vector<ll> w2 = {};
        while (a != b) {
            if (ln[a] > ln[b]) {
                w1.push_back(gsqn[a].S);
                a = gsqn[a].F;
            } else {
                w2.push_back(gsqn[b].S);
                b = gsqn[b].F;
            }
        }
        reverse(w2.begin(), w2.end());
        for (auto &x : w2)
            w1.push_back(x);
        vector<ll> l(w1.size() + 1, 0);
        vector<ll> r(w1.size() + 1, 0);
        for (int i = 0; i < w1.size(); i++)
            l[i + 1] = l[i] + w1[i];
        for (int i = w1.size() - 1; i >= 0; i--)
            r[i] = r[i + 1] + w1[i];
        int ans = 0;
        if (l[w1.size()] == d)
            ans++;
        for (int i = 1; i < w1.size(); i++) {
            // cout << l[i] * r[i] << endl;
            if (l[i] * r[i] == d)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}