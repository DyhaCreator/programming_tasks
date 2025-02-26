#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int col = 1;
int n, m;

void dfs(vector<vector<ll>> &g, vector<ll> &used, int index) {
    used[index] = col;
    for (auto &x : g[index]) {
        if (used[x] == 0) {
            dfs(g, used, x);
        }
    }
}

int main() {
    cin >> n >> m;
    vector<ll> c(n);
    for (auto &x : c)
        cin >> x;
    /*if (m == 0) {
        vector<pair<ll, ll>> d(n);
        for (int i = 0; i < n; i++)
            d[i] = {c[i], i + 1};
        sort(d.begin(), d.end());
        cout << n - 1 << endl;
        for (int i = 1; i < n; i++)
            cout << d[0].S << " " << d[i].S << endl;
        return 0;
    }*/
    vector<vector<ll>> g(n);
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    set<pair<pair<ll, ll>, ll>> st;
    vector<ll> used(n);
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            dfs(g, used, i);
            col++;
        }
    }
    vector<ll> mn(col - 1, -1);
    for (int i = 0; i < n; i++) {
        if (mn[used[i] - 1] == -1 || c[mn[used[i] - 1]] > c[i])
            mn[used[i] - 1] = i;
    }
    for (int i = 0; i < col - 1; i++)
        st.insert({{c[mn[i]], mn[i]}, i});
    /*for (auto &x : st)
        cout << x.F.F << " " << x.F.S << " " << x.S << endl;
    cout << endl;*/
    vector<pair<ll, ll>> ans = {};
    for (int i = 0; i < col - 2; i++) {
        ll a1 = st.begin()->F.S;
        ll b1 = st.begin()->S;
        st.erase(*st.begin());
        ll a2 = st.begin()->F.S;
        ll b2 = st.begin()->S;
        st.erase(*st.begin());
        ans.push_back({a1, a2});
        if (c[a1] < c[a2])
            st.insert({{c[a1], a1}, b1});
        else
            st.insert({{c[a2], a2}, b1});
        /*for (auto &x : st)
            cout << x.F.F << " " << x.F.S << " " << x.S << endl;
        cout << endl;*/
    }
    cout << ans.size() << endl;
    for (auto &x : ans)
        cout << x.F + 1 << " " << x.S + 1 << endl;
    return 0;
}