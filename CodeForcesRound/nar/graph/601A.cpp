#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g1(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g1[a].push_back(b);
        g1[b].push_back(a);
    }
    vector<vector<int>> g2(n);
    for (int i = 0; i < n; i++) {
        vector<int> count(n);
        for (auto &x : g1[i])
            count[x] = 1;
        for (int j = 0; j < n; j++)
            if (count[j] == 0 && j != i) g2[i].push_back(j);
    }
    int ans = INF;
    vector<int> used(n, INF);
    vector<int> pref(n, -1);
    queue<int> q;
    q.push(0);
    used[0] = 0;
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        for (auto &x : g1[num]) {
            if (used[x] >= INF) {
                used[x] = used[num] + 1;
                pref[x] = num;
                q.push(x);
            }
        }
    }
    if (used[n - 1] < INF) {
        vector<int> cn(n);
        int index = n - 1;
        while (index != 0) {
            index = pref[index];
            cn[index] = 1;
        }
        vector<int> used2(n, INF);
        q.push(0);
        used2[0] = 0;
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            for (auto &x : g2[num]) {
                if (used2[x] >= INF && cn[x] == 0) {
                    used2[x] = used2[num] + 1;
                    q.push(x);
                }
            }
        }
        ans = max(used[n - 1], used2[n - 1]);
    }
    vector<int> used2(n, INF);
    vector<int> pref2(n, -1);
    q.push(0);
    used2[0] = 0;
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        for (auto &x : g2[num]) {
            if (used2[x] >= INF) {
                used2[x] = used2[num] + 1;
                pref2[x] = num;
                q.push(x);
            }
        }
    }
    if (used2[n - 1] < INF) {
        vector<int> cn(n);
        int index = n - 1;
        while (index != 0) {
            index = pref2[index];
            cn[index] = 1;
        }
        vector<int> used3(n, INF);
        used3[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            for (auto &x : g1[num]) {
                if (used3[x] >= INF && cn[x] == 0) {
                    used3[x] = used3[num] + 1;
                    q.push(x);
                }
            }
        }
        ans = min(ans, max(used2[n - 1], used3[n - 1]));
    }
    if (ans >= INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}