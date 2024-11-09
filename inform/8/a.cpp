#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;



int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &x : a)
        for (auto &y : x)
            cin >> y;
    vector<pair<int, int>> b = {};
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (a[y][x] != 0) b.push_back({y, x});
        }
    }
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                ans[i][j] = a[i][j];
                continue;
            } 
            int minD = INF;
            int minDc = 0;
            int found = 0;
            for (auto &z : b) {
                int y = z.first;
                int x = z.second;
                if (a[y][x] != 0) {
                    if (abs(i - y) + abs(j - x) < minD) {
                        minD = abs(i - y) + abs(j - x);
                        minDc = a[y][x];
                        found = 0;
                    } else if (abs(i - y) + abs(j - x) == minD) {
                        found = 1;
                    }
                }
            }
            if (!found) {
                ans[i][j] = minDc;
            }
        }
    }
    for (auto &x : ans) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    } 
    return 0;
}