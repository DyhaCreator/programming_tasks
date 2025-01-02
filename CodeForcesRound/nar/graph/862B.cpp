#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs(vector<vector<int>> &g, vector<int> &used, int index, int col) {
    used[index] = col;
    for (auto &x : g[index]) {
        if (used[x] == -1) {
            dfs(g, used, x, (col + 1) % 2);
        }
    }
}

int main() {
    ll n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> used(n, -1);
    dfs(g, used, 0, 0);
    ll sum = 0;
    for (auto &x : used)
        sum += x;
    cout << sum * (n - sum) - (n - 1) << endl;
    return 0;
}