#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

struct int2{
    int first, second;
    int2() {}
    int2(int x, int y) {
        this->first = x;
        this->second = y;
    }
};

int n, m, s, t;
vector<vector<pair<ll, ll>>> g;

vector<int2> d(int start) {
    vector<int2> dist(n, {INF, -1});
    dist[start] = {0, -1};
    vector<int> visited(n);

    for (int i = 0; i < n; i++) {
        int near = -1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && (dist[near].first > dist[v].first)) {
                near = v;
            }
        }

        visited[near] = 1;

        for (auto &[to, weight] : g[near]) {
            if (dist[to].first > dist[near].first + weight) {
                dist[to].first = dist[near].first + weight;
                dist[to].second = near;
            }
        }
    }

    return dist;
}

int main() {
    cin >> n >> m >> s >> t;

    g = vector<vector<pair<ll, ll>>>(n);
    for (int i = 0; i < m; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        a--;
        b--;
        g[a].push_back({b, weight});
        g[b].push_back({a, weight});
    }

    vector<int2> dist = d(s - 1);

    /*for (auto &[len, prev] : dist)
        cout << len << " ";
    cout << endl;*/

    cout << dist[t - 1].first << " ";

    vector<int> ans = {};
    int p = t - 1;
    while (p != -1) {
        ans.push_back(p);
        p = dist[p].second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto &x : ans)
        cout << x + 1 << " ";
    cout << endl;
    return 0;
}