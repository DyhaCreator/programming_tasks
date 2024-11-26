#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int sum = 0;
int cnt = 0;

void dfs(vector<vector<int>> &g, vector<int> &used, int index, int len) {
    used[index] = 1;
    int c = 0;
    for (auto &x : g[index]) {
        if (used[x] == 0) {
            dfs(g, used, x, len + 1);
            c++;
        }
    }
    if (c == 0) {
        sum += len;
        cnt++;
    }
    used[index] = 0;
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> used(n);
    dfs(g, used, 0, 0);
    printf("%.8f\n", (double)sum / (double)cnt);
    return 0;
}