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
    k--;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x >= 0) g[i].push_back({j, x});
        }
    }
    vector<int> used(n, INF);
    vector<int> pred(n, -1);
    vector<int> visited(n, 0);
    used[k] = 0;
    for (int j = 0; j < n; j++) {
        int indexMin = -1;
        for (int l = 0; l < n; l++) {
            if (visited[l] == 0 && (used[indexMin] > used[l] || indexMin == -1)) {
                indexMin = l;
            }
        }
        visited[indexMin] = 1;
        for (auto &x : g[indexMin]) {
            if (used[x.first] > used[indexMin] + x.second) {
                used[x.first] = used[indexMin] + x.second;
                pred[x.first] = indexMin;
            }
        }
        // cout << indexMin << endl;
        /*for (auto &x : visited)
            cout << x << " ";
        cout << endl;*/
    }
    /*for (auto &x : used)
        cout << x << " ";
    cout << endl;
    for (auto &x : pred)
        cout << x << " ";
    cout << endl;*/

    int ans1 = 0;
    for (auto &x : used)
        ans1 = max(ans1, x);
    cout << ans1 << endl;

    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++) {
        int index = pred[i];
        while (index != -1) {
            ans[i].push_back(index);
            index = pred[index];
        }
        reverse(ans[i].begin(), ans[i].end());
        ans[i].push_back(i);
    }

    /*for (auto &x : ans) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    map<pair<int, int>, int> mp;
    for (auto &x : ans) {
        for (int i = 0; i < x.size() - 1; i++) {
            if (mp[{x[i], x[i + 1]}] == 0) {
                cout << x[i] + 1 << " " << x[i + 1] + 1 << endl;
                mp[{x[i], x[i + 1]}] = 1;
            }
        }
    }

    return 0;
}