#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n;
vector<vector<int>> g;
vector<int>ans = {};

bool dfs(int t, vector<int> &visited) {
    // cout << t << endl;
    visited[t] = 1;
    if (t == n - 1) {
        ans.push_back(t);
        return true;
    }

    for (auto &x : g[t]) {
        if (visited[x] == 0) {
            if (dfs(x, visited)) {
                ans.push_back(t);
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> n;
    g = vector<vector<int>> (n, vector<int>());
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        g[i].push_back(a - 1);
        g[a - 1].push_back(i);
    }
    /*for (auto &x : g) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }*/
    vector<int>visited(n);
    dfs(0, visited);
    reverse(ans.begin(), ans.end());
    for (auto &x : ans) {
        cout << x + 1 << " ";
    }
    cout << endl;
    return 0;
}