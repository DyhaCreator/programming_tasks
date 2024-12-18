#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

ll ans = INF;
int k = 0;
int n = 0;
vector<pair<int, int>> coords = {};

int f(int index, vector<int> &d, vector<int> &used, ll len, vector<vector<vector<ll>>> &dist) {
    if (index == k + 1) {
        ans = min(len, ans);
        /*cout << len << "-> ";
        for (auto &x : d)
            cout << x << " ";
        cout << endl;*/
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            used[i] = 1;
            d[index] = i;
            if (index > 0) {
                f(index + 1, d, used, len + dist[d[index - 1]][coords[i].first][coords[i].second], dist);
            } else {
                f(index + 1, d, used, len, dist);
            }
            used[i] = 0;
        }
    }
    return 0;
}

int main() {
    int w, h;
    string enter;
    cin >> w >> h >> k;
    getline(cin, enter);
    vector<string> map(w);
    for (auto &x : map)
        getline(cin, x);
    /*for (auto &x : map)
        cout << x << endl;*/
    for (int y = 0; y < w; y++) {
        for (int x = 0; x < h; x++) {
            if (map[y][x] == 'H' || map[y][x] == 'R') {
                n++;
                coords.push_back({y, x});
            }
        }
    }
    vector<vector<vector<ll>>> dist(n, vector<vector<ll>>(w, vector<ll>(h, INF)));
    for (int i = 0; i < n; i++) {
        dist[i][coords[i].first][coords[i].second] = 0;
        queue<pair<int, int>> q;
        q.push({coords[i].first, coords[i].second});
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            if (y > 0 && dist[i][y - 1][x] == INF && map[y - 1][x] != '#') {
                dist[i][y - 1][x] = dist[i][y][x] + 1;
                q.push({y - 1, x});
            }
            if (x > 0 && dist[i][y][x - 1] == INF && map[y][x - 1] != '#') {
                dist[i][y][x - 1] = dist[i][y][x] + 1;
                q.push({y, x - 1});
            }
            if (y < w - 1 && dist[i][y + 1][x] == INF && map[y + 1][x] != '#') {
                dist[i][y + 1][x] = dist[i][y][x] + 1;
                q.push({y + 1, x});
            }
            if (x < h - 1 && dist[i][y][x + 1] == INF && map[y][x + 1] != '#') {
                dist[i][y][x + 1] = dist[i][y][x] + 1;
                q.push({y, x + 1});
            }
        }
        /*for (auto &x : dist[i]) {
            for (auto &y : x)
                cout << y << " ";
            cout << endl;
        }
        cout << endl;*/
    }
    vector<int> ccc(k + 1);
    ccc[0] = 0;
    vector<int> used(n, 0);
    used[0] = 1;
    f(1, ccc, used, 0, dist);
    cout << ans << endl;
    return 0;
}