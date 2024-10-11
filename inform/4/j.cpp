#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        int x;
        cin >> x;
        if (x >= 0) g[i].push_back({j, x});}
    vector<int> dist(n, INF);
    vector<int> pred(n, -1);
    vector<int> used(n, 0);
    k--;
    dist[k] = 0;
    for (int j = 0; j < n; j++) {
        int num = -1;
        for (int v = 0; v < n; v++)
            if (used[v] == 0 && (dist[num] > dist[v] || num == -1))
                num = v;
        used[num] = 1;
        for (auto &x : g[num])
            if (dist[x.first] > dist[num] + x.second) {
                dist[x.first] = dist[num] + x.second;
                pred[x.first] = num;
            }
    }
    int maxLen = 0;
    for (auto &x : dist)
        maxLen = max(maxLen, x);
    cout << maxLen << endl;

    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++) {
        int index = pred[i];
        while (index != -1) {
            ans[i].push_back(index + 1);
            index = pred[index];
        }
        reverse(ans[i].begin(), ans[i].end());
        ans[i].push_back(i + 1);
    }
    map<pair<int, int>, int> mp;
    for (auto &x : ans) {
        for (int i = 0; i < x.size() - 1; i++) {
            if (mp[{x[i], x[i + 1]}] == 0) {
                cout << x[i] << " " << x[i + 1] << endl;
                mp[{x[i], x[i + 1]}] = 1;
            }
        }
    }

    return 0;
}