#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs(int v, vector<int> &used, vector<int> &c, vector<vector<int>> &g) {
    vector<int> cntf = {};
    vector<int> cntp = {};
    for (auto &x : g[v]) {
        dfs(x, used, c, g);
        used[v] += used[x];
        cntf.push_back(used[x]);
        cntp.push_back(c[x]);
    }
    if (cntf.size() > 0) {
        int sumf = cntf[0];
        int sump = cntp[0];
        
        for (int i = 1; i < cntf.size(); i++) {
            if (cntf[i] > sumf) {
                if (sump * 2 >= cntf[i] - sumf) {
                    sump = (sump * 2 + (cntf[i] - sumf)) / 2;
                    cntf[i] = sumf + (cntf[i] - sumf) % 2;
                } else if (sump * 2 < cntf[i] - sumf) {
                    cntf[i] -= sump * 2;
                    sump *= 2;
                }
                sump +
            } else if (cntf[i] < sumf) {
                
            } else {
                sumf = 0;
                sump += cntf[i] + cntp[i];
            }
        }
        for (auto &x : cntf)
            cout << x << " ";
        cout << endl;
        for (auto &x : cntp)
            cout << x << " ";
        cout << endl;
        cout << sumf << " " << sump << endl;
        c[v] = sump;
    }

    used[v]++;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n - 1);
    for (auto &x : p)
        cin >> x;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        g[p[i] - 1].push_back(i + 1);
        // g[i].push_back(p[i] - 1);
    }
    vector<int> used(n);
    vector<int> c(n);
    dfs(0, used, c, g);
    for (auto &x : used)
        cout << x << " ";
    cout << endl;
    for (auto &x : c)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}