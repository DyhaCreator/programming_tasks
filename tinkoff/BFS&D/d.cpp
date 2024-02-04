#include <iostream>
#include <queue>
#include <vector>
#include <set>
#define ll long long
#define INF 1000000007
using namespace std;

struct int2{
    ll x, y;
    int2() {}
    int2(ll x, ll y) {
        this->x = x;
        this->y = y;
    }
};

vector<vector<int2>> g;
ll n;

vector<ll> d(int start) {
    vector<ll> dist(n + 1, INF);
    vector<ll> visited(n + 1, 0);
    dist[start] = 0;

    /*set<pair<ll, ll>> st;
    for (int i = 0; i < n; i++) {
        st.insert({dist[i], i});
    }*/

    for (ll i = 0; i < n; i++) {
        /*ll near = st.begin()->second;
        st.erase(st.begin());*/
        ll near = -1;
        for (ll v = 0; v < n; v++) {
            if (!visited[v] && (near == -1 || dist[near] > dist[v])) {
                // dist[near] = dist[v];
                near = v;
            }
        }
        /*cout << near << endl;
        for (auto &x : dist)
            cout << x << ' ';
        cout << endl;*/
        if (dist[near] == INF) {
            break;
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
    vector<int2> v(n);
    g = vector<vector<int2>>(n, vector<int2>());
    for (auto &x : v) {
        cin >> x.x >> x.y;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                g[i].push_back(int2(j, (v[i].x - v[j].x) * (v[i].x - v[j].x) + 
                               (v[i].y - v[j].y) * (v[i].y - v[j].y)));
                // cout << g[i].back().x << " ";
            }
        }
        // cout << endl;
    }

    int a, b;
    cin >> a >> b;
    a--;
    b--;

    vector<ll> dist = d(a);

    cout << dist[b] << endl;
    return 0;
}