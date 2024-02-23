#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int v = 0; v < n; v++) {
        dist[v][v] = 0;
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int a;
            cin >> a;
            dist[y][x] = min(dist[y][x], a);
        }
    }

    for (int v = 0; v < n; v++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (dist[y][v] != INF && dist[v][x] != INF && dist[y][x] > dist[y][v] + dist[v][y]) {
                    dist[y][x] = std::max(dist[y][v] + dist[v][y], -INF);
                }
            }
        }
    }


    for (auto &x : dist) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    vector<vector<int>> ans(n, vector<int>(n, 1));

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (dist[y][x] == INF) {
                ans[y][x] = 0;
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