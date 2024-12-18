#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    string str;
    int k;
    cin >> str >> k;
    int m;
    cin >> m;
    vector<int> dig(m);
    for (auto &x : dig)
        cin >> x;
    sort(dig.begin(), dig.end());
    // vector<vector<int>> g(k);
    vector<vector<pair<int, int>>> g(k);
    for (int i = 0; i < k; i++) {
        for (auto &x : dig) {
            int ost = (i * 10 + x) % k;
            g[i].push_back({ost, x});
        }
    }

    int start = 0;
    for (auto &x : str)
        start = (start * 10 + x - '0') % k;

    queue<int> q;
    q.push(start);
    vector<int> used(k, INF);
    used[start] = 0;
    vector<int> xxx(k, -1);
    vector<int> prev(k, -1);
    while (!q.empty()) {
        int index = q.front();
        q.pop();

        for (auto &x : g[index]) {
            if (used[x.first] == INF) {
                used[x.first] = used[index] + 1;
                prev[x.first] = index;
                xxx[x.first] = x.second;
                q.push(x.first);
            }
        }
    }

    if (used[0] == INF) {
        cout << -1 << endl;
        return 0;
    }

    // cout << used[0] << endl;

    vector<int> ans(used[0]);
    int p = 0;
    for (auto &x : ans) {
        x = xxx[p];
        p = prev[p];
    }
    reverse(ans.begin(), ans.end());
    cout << str;
    for (auto &x : ans) {
        cout << x;
    }
    cout << endl;
    return 0;
}