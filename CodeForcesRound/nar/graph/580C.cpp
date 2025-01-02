#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int ans = 0;
int n, m;

void dfs(vector<vector<int>> &g, vector<int> &a, vector<int> &used, int index, int cnt) {
    used[index] = cnt;
    int f = 0;
    for (auto &x : g[index]) {
        if (used[x] == -1) {
            f = 1;
            if (((a[x] == 0)?0:cnt + 1) <= m) dfs(g, a, used, x, ((a[x] == 0)?0:cnt + 1));
        }
    }
    if (f == 0 && cnt <= m) ans++; 
}

int main() {
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> used(n, -1);
    dfs(g, a, used, 0, a[0]);
    
    cout << ans << endl;
    return 0;
}