#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000000000007LL
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> matrix(n, vector<ll>(n));

    for (ll y = 0; y < n; y++) {
        for (ll x = 0; x < n; x++) {
            cin >> matrix[y][x];
        }
    }

    vector<vector<ll>> dist(n, vector<ll>(n, INF));

    for (ll y = 0; y < n; y++) {
        for (ll x = 0; x < n; x++) {
            if (matrix[y][x] != 0) {
                dist[y][x] = matrix[y][x];
            } 
        }
    }

    for (ll i = 0; i < n; i++) {
        vector<vector<ll>> newDist(n, vector<ll>(n));
        for (ll y = 0; y < n; y++) {
            for (ll x = 0; x < n; x++) {
                ll a = dist[y][x];
                ll b = dist[i][x] + dist[y][i];
                if (dist[y][i] != INF && dist[i][x] != INF) {
                    newDist[y][x] = std::min(a, b);
                } else {
                    newDist[y][x] = a;
                }
                newDist[y][x] = std::max(newDist[y][x], -INF);
            }
        }
        dist = newDist;
    }

    vector<vector<ll>> ans(n, vector<ll>(n));

    for (ll y = 0; y < n; y++) {
        for (ll x = 0; x < n; x++) {
            if (dist[y][x] == INF) {
                ans[y][x] = 0;
            } else {
                ans[y][x] = 1;
            }
        }
    }

    for (int v = 0; v < n; v++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (dist[y][v] != INF && dist[v][x] != INF && dist[v][v] < 0) {
                    ans[y][x] = 2;
                }
            }
        }
    }

    for (auto &x : ans) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}