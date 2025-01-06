#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int y1, x1;
    cin >> y1 >> x1;
    y1--;x1--;
    int y2, x2;
    cin >> y2 >> x2;
    y2--;x2--;
    vector<vector<int>> d1(n, vector<int>(n, INF));
    queue<pair<int, int>> q;
    q.push({y1, x1});
    d1[y1][x1] = 0;
    while (!q.empty()) {
        int yc = q.front().F;
        int xc = q.front().S;
        q.pop();
        for (int y = -2; y <= 2; y++) {
            for (int x = -2; x <= 2; x++) {
                if ((abs(y) == 2 && abs(x) == 1) || (abs(y) == 1 && abs(x) == 2)) {
                    if (yc + y >= 0 && yc + y < n && xc + x < n && xc + x >= 0 && d1[yc + y][xc + x] > d1[yc][xc] + 1) {
                        d1[yc + y][xc + x] = d1[yc][xc] + 1;
                        q.push({yc + y, xc + x});
                    }
                }
            }
        }
    }
    vector<vector<int>> d2(n, vector<int>(n, INF));
    q.push({y2, x2});
    d2[y2][x2] = 0;
    while (!q.empty()) {
        int yc = q.front().F;
        int xc = q.front().S;
        q.pop();
        for (int y = -2; y <= 2; y++) {
            for (int x = -2; x <= 2; x++) {
                if ((abs(y) == 2 && abs(x) == 1) || (abs(y) == 1 && abs(x) == 2)) {
                    if (yc + y >= 0 && yc + y < n && xc + x < n && xc + x >= 0 && d2[yc + y][xc + x] > d2[yc][xc] + 1) {
                        d2[yc + y][xc + x] = d2[yc][xc] + 1;
                        q.push({yc + y, xc + x});
                    }
                }
            }
        }
    }
    /*for (auto &x : d1) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << endl;
    for (auto &x : d2) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    int ans = INF;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (d1[y][x] == d2[y][x]) {
                ans = min(ans, d1[y][x]);
            }
        }
    }
    if (ans == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}