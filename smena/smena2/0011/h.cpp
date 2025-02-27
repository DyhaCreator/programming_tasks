#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for (auto &x : a) {
        for (auto &y : x)
            cin >> y;
    }
    for (auto &x : b) {
        for (auto &y : x)
            cin >> y;
    }
    vector<vector<int>> cnta = {};
    for (int i = 0; i < n + m; i++) {
        cnta.push_back({});
        for (int j = 0; j <= i; j++) {
            if (j < n && i - j < m) cnta[cnta.size() - 1].push_back(a[j][i - j]);
        }
    }
    vector<vector<int>> cntb = {};
    for (int i = 0; i < n + m; i++) {
        cntb.push_back({});
        for (int j = 0; j <= i; j++) {
            if (j < n && i - j < m) cntb[cntb.size() - 1].push_back(b[j][i - j]);
        }
    }
    for (auto &x : cnta)
        sort(x.begin(), x.end());
    for (auto &x : cntb)
        sort(x.begin(), x.end());

    if (cnta == cntb) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}