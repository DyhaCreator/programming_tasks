#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g1(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            a--;
            g1[a].push_back(i);
        }
    }
    ll ans = 1000000000000000000;
    for (int s = 0; s < n; s++) {
        vector<int> used(n, INF);
        queue<int> q;
        used[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            for (auto &x : g1[num]) {
                if (used[x] == INF) {
                    used[x] = used[num] + 1;
                    q.push(x);
                }
            }
        }
        int fINF = 0;
        for (auto &x : used)
            if (x == INF) fINF = 1;
        if (fINF) continue;
        int mx = 0;
        for (auto &x : used)
            mx = max(mx, x);
        mx++;
        vector<int> col(mx);
        for (auto &x : used)
            col[x]++;
        reverse(col.begin(), col.end());
        vector<ll> d(mx + 1);
        for (int i = 0; i < mx; i++)
            d[i + 1] = d[i] + col[i] * k;
        ll sum = 0;
        for (auto &x : d)
            sum += x;
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}