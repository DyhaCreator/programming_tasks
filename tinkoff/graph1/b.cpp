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
    int s, f;
    cin >> s >> f;
    s--;f--;
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
    d[s] = 0;
    for (int i = 0; i < n; i++)
        st.insert({d[i], i});
    for (int i = 0; i < n; i++) {
        int num = (*st.begin()).S;
        st.erase(*st.begin());
        for (auto &x : g[num]) {
            if (d[x.F] > d[num] + x.S) {
                st.erase({d[x.F], x.F});
                d[x.F] = d[num] + x.S;
                pref[x.F] = num;
                st.insert({d[x.F], x.F});
            }
        }
    }
    if (d[f] == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << d[f] << endl;
    vector<int> ans = {};
    int index = f;
    while (index != -1) {
        ans.push_back(index);
        index = pref[index];
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (auto &x : ans)
        cout << x + 1 << " ";
    cout << endl;
    return 0;
}