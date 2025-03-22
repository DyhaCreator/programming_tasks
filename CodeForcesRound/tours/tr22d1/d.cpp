#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> g = {{1, 2}, {2, 0}, {0, 1}};
    n--;
    ll s = n;
    while (s > 0) {
        g.push_back({});
        ll y = 2;
        while (y * (y - 1) / 2 <= s && y < g.size()) y++;
        y--;
        for (int i = 0; i < y; i++) {
            g[i].push_back(g.size() - 1);
            g[g.size() - 1].push_back(i);
        }
        s -= y * (y - 1) / 2;
    }
    vector<vector<int>> m(g.size(), vector<int>(g.size()));
    for (int y = 0; y < g.size(); y++) {
        for (auto &x : g[y]) {
            m[y][x] = 1;
        }
    }
    cout << g.size() << endl;
    for (auto &x : m) {
        for (auto &y : x)
            cout << y;
        cout << endl;
    }
    return 0;
}