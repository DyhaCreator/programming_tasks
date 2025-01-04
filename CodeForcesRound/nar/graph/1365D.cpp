#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    vector<string> b = a;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (b[y][x] == 'B') {
                if (y > 0 && a[y - 1][x] != 'G') a[y - 1][x] = '#';
                else if (y > 0) {
                    cout << "No" << endl;
                    return;
                }
                if (x > 0 && a[y][x - 1] != 'G') a[y][x - 1] = '#';
                else if (x > 0) {
                    cout << "No" << endl;
                    return;
                }
                if (y < n - 1 && a[y + 1][x] != 'G') a[y + 1][x] = '#';
                else if (y < n - 1) {
                    cout << "No" << endl;
                    return;
                }
                if (x < m - 1 && a[y][x + 1] != 'G') a[y][x + 1] = '#';
                else if (x < m - 1) {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    vector<vector<int>> used(n, vector<int>(m, INF));
    if (a[n - 1][m - 1] != '#') used[n - 1][m - 1] = 0;
    queue<pair<int, int>> q;
    q.push({n - 1, m - 1});
    while (!q.empty()) {
        pair<int, int> num = q.front();
        q.pop();
        if (num.F > 0 && a[num.F - 1][num.S] != '#' && used[num.F - 1][num.S] == INF) {
            used[num.F - 1][num.S] = used[num.F][num.S] + 1;
            q.push({num.F - 1, num.S});
        }
        if (num.S > 0 && a[num.F][num.S - 1] != '#' && used[num.F][num.S - 1] == INF) {
            used[num.F][num.S - 1] = used[num.F][num.S] + 1;
            q.push({num.F, num.S - 1});
        }
        if (num.F < n - 1 && a[num.F + 1][num.S] != '#' && used[num.F + 1][num.S] == INF) {
            used[num.F + 1][num.S] = used[num.F][num.S] + 1;
            q.push({num.F + 1, num.S});
        }
        if (num.S < m - 1 && a[num.F][num.S + 1] != '#' && used[num.F][num.S + 1] == INF) {
            used[num.F][num.S + 1] = used[num.F][num.S] + 1;
            q.push({num.F, num.S + 1});
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (a[y][x] == 'G' && used[y][x] >= INF) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}