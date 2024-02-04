#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000000007LL
using namespace std;

int n;
vector<vector<pair<ll, ll>>> g;

vector<ll> d(int start) {
    vector<ll> dist(n, INF);
    dist[start] = 0;
    /*cout << start << endl;
    for (auto &x : dist)
        cout << x << " ";
    cout << endl;*/

    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++) {
        int near = -1;

        for (int v = 0; v < n; v++) {
            if (visited[v] == 0 && (near == -1 || dist[near] > dist[v])) {
                near = v;
            }
        }
        /*cout << near << endl;
        for (auto &x : dist)
            cout << x << " ";
        cout << endl;*/

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
    vector<pair<ll, ll>> coords(n);
    g = vector<vector<pair<ll, ll>>>(n);
    for (auto &[x, y] : coords)
        cin >> x >> y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                g[i].push_back({j, 
                (coords[i].first - coords[j].first) * (coords[i].first - coords[j].first) + 
                (coords[i].second - coords[j].second) * (coords[i].second - coords[j].second)});
            }
        }
    }
    /*for (auto &x : g) {
        for (auto &[to, weight] : x) {
            cout << to << " " << weight << endl;
        }
    }*/

    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    vector<ll>dist = d(a);

    cout << dist[b] << endl;
    exit(0);
    return 0;
}