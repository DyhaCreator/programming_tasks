#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int n;
vector<vector<pair<ll, ll>>> g;

vector<ll> deixtra(int start) {
    vector<ll> dist(n, INF);
    dist[start] = 0;
    vector<int> visited(n);

    for (int i = 0; i < n; i++) {
        int near = -1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && (near == -1 || dist[near] > dist[v])) {
                near = v;
            }
        }

        visited[near] = 1;

        for (auto &[to, weight] : g[near]) {
            if (dist[to] > dist[near] + weight) {
                dist[to] = dist[near] + weight;
            }
        } 
    }
    return dist;
}

int main() {
    cin >> n;
    vector<pair<ll, ll>> v(n);
    g = vector<vector<pair<ll, ll>>>(n);
    for (auto &[x, y] : v)
        cin >> x >> y;
    
    int start, finish;
    cin >> start >> finish;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            g[i].push_back({j,
            (v[i].first - v[j].first) * (v[i].first - v[j].first) + 
            (v[i].second - v[j].second) * (v[i].second - v[j].second)});

            g[j].push_back({i,
            (v[i].first - v[j].first) * (v[i].first - v[j].first) + 
            (v[i].second - v[j].second) * (v[i].second - v[j].second)});
        }
    }

    /*for (int i = 0; i < n; i++) {
        cout << i << endl;
        for (auto &x : g[i]) {
            cout << x.first << " " << x.second << endl;
        }
        cout << endl;
    }*/

    vector<ll> dist = deixtra(start - 1);

    /*for (auto &x : dist)
        cout << x << " ";
    cout << endl;*/

    cout << dist[finish - 1] << endl;
    return 0;
}