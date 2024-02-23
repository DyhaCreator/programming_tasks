#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> matrix[y][x];
        }
    }

    vector<vector<int>> dist(n, vector<int>(n));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (matrix[y][x] == -1) {
                dist[y][x] = INF;
            } else {
                dist[y][x] = matrix[y][x];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        vector<vector<int>> newDist(n, vector<int>(n));

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                int a = dist[y][x];
                int b = dist[i][x] + dist[y][i];
                newDist[y][x] = std::min(a, b);
            }
        }

        dist = newDist;
    }

    int ans = -1;

    for (auto &x : dist) {
        for (auto &y : x) {
            // cout << y << " ";
            if (y != INF) ans = std::max(y, ans);
        }
        // cout << endl;
    }

    cout << ans << endl;
    return 0;
}