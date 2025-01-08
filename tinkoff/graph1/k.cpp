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
    vector<vector<pair<int, pair<int, int>>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        a--;b--;
        t -= 3000000;
        if (t > 0) {
            t /= 100;
            g[a].push_back({b, {c, t}});
            g[b].push_back({a, {c, t}});
        }
    }
    vector<set<pair<int, int>>> d(n);
    set<pair<int, int>> st;
    d[0].insert({0, 0});
    st.insert({0, 0});
    for (int i = 1; i < n; i++)
        st.insert({-INF, i});
    for (int i = 0; i < n; i++) {
        int num = (*st.begin()).S;
        st.erase(*st.begin());
        for (auto &x : g[num]) {
            for (auto &y : d[num]) {
                st.erase({((d[x.F].size() == 0)?-INF:(*d[x.F].end()).S), x.F});
                d[x.F].insert({y.F + x.S.F, y.S + x.S.S});
                st.insert({(*d[x.F].end()).S, x.F});
            }
        }
    }
    for (auto &x : d) {
        for (auto &y : x) {
            cout << y.F << " " << y.S << "  ";
        }
        cout << endl;
    }
    return 0;
}