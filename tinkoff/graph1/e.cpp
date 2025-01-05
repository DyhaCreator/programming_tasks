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
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vector<int> d(n, INF);
    set<pair<int, int>> st;
    d[0] = 0;
    for (int i = 0; i < n; i++)
        st.insert({d[i], i});
    for (int i = 0; i < n; i++) {
        int num = (*st.begin()).S;
        st.erase({d[num], num});
        for (auto &x : g[num]) {
            if (d[x.F] > d[num] + x.S) {
                st.erase({d[x.F], x.F});
                d[x.F] = d[num] + x.S;
                st.insert({d[x.F], x.F});
            }
        }
    }
    if (d[n - 1] >= INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << d[n - 1] << endl;
    return 0;
}