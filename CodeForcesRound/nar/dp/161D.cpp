#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int n, k;

void dfs(int v, vector<vector<int>> &g, vector<int> &used, vector<vector<int>> &s) {
    used[v] = 2;
    for (auto &x : g[v]) {
        if (used[x] == 0) {
            dfs(x, g, used, s);
        }
    }
    for (int i = 0; i <= k; i++) {
        for (auto &x : g[v]) {
            if (used[x] == 1) {
                s[v][i] += s[x][i - 1];
            }
        }
    }
    used[v] = 1;
}

int main() {
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> used(n);
    vector<vector<int>> s(n, vector<int>(k + 1, 0));
    for (auto &x : s)
        x[0] = 1;
    dfs(0, g, used, s);
    for (auto &x : s) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    ll sum = 0;
    for (auto &x : s) {
        sum += x[k];
    }
    cout << sum << endl;
    for (int i = k - 1; i > k / 2; i--) {
        for (int j = 0; j < n; j++) {
            cout << s[j][i] << " " << s[j][k - i] - 1 << endl;
            sum += s[j][i] * (s[j][k - i] - 1);
        }
    }
    if (k % 2 == 0) {
        for (int j = 0; j < n; j++) {
            // cout << s[j][k / 2] / 2 << endl;
            sum += s[j][k / 2] / 2;
        }
    }
    cout << sum << endl;
    return 0;
}