#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ifstream cin("dijkstra.in");
    ofstream cout("dijkstra.out");
    int n, l, r;
    cin >> n >> l >> r;
    l--;r--;
    cout << n << " " << l << " " << r << endl;
    /*vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (i != j && a != -1) {
                g[i].push_back(j);
                // g[i].push_back({j, a});
            }
        }
    }*/
    /*vector<int> d(n, INF);
    vector<int> used(n);
    d[l] = 0;
    for (int i = 0; i < n; i++) {
        int mn = -1;
        for (int j = 0; j < n; j++) {
            if ((mn == -1 || d[mn] > d[j]) && used[j] == 0) {
                mn = j;
            }
        }
        used[mn] = 1;
        for (auto &x : g[mn]) {
            if (d[x.F] > d[mn] + x.S) {
                d[x.F] = d[mn] + x.S;
            }
        }
    }
    if (d[r] == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << d[r] << endl;*/
    return 0;
}