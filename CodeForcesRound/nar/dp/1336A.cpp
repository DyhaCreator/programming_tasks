#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs(vector<vector<int>> &g, vector<int> &ln, int index, int len) {
    ln[index] = len;
    for (auto &x : g[index]) {
        if (ln[x] == 0) {
            dfs(g, ln, x, len + 1);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> ln(n);
    dfs(g, ln, 0, 1);
    for (auto &x : ln) x--;
    for (auto &x : ln)
        cout << x << " ";
    cout << endl;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        
    }
    return 0;
}