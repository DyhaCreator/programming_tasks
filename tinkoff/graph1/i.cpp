#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vector<int> d(n, INF);
    vector<int> pref(n, -1);
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            d[i] = 0;
            pref[i] = i;
        }
    }
    for (int i = 0; i < n; i++)
        st.insert({d[i], i});
    for (int i = 0; i < n; i++) {
        int num = (*st.begin()).S;
        st.erase(*st.begin());
        for (auto &x : g[num]) {
            if (d[x.F] > d[num] + x.S) {
                st.erase({d[x.F], x.F});
                d[x.F] = d[num] + x.S;
                pref[x.F] = pref[num];
                st.insert({d[x.F], x.F});
            }
        }
    }
    int s, f, c = INF;
    for (int i = 0; i < n; i++) {
        if (a[i] == 2 && c > d[i]) {
            c = d[i];
            s = pref[i];
            f = i;
        }
    }
    if (c == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << s + 1 << " " << f + 1 << " " << c << endl;
    return 0;
}