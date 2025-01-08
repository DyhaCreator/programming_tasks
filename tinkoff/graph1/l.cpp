#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int m;
    cin >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> used1(n, INF);
    vector<int> used2(n, INF);
    vector<int> used(n, 0);
    set<pair<pair<int, int>, int>> st;
    used1[0] = 0;
    used2[0] = INF;
    used[0] = 1;
    for (int i = 0; i < n; i++)
        st.insert({{used1[i], used2[i]}, i});
    for (int i = 0; i < n; i++) {
        int num = (*st.begin()).S;
        st.erase(*st.begin());
        used[num] = 1;
        for (auto &x : g[num]) {
            if (used[x] == 0) {
                st.erase({{used1[x], used2[x]}, x});
                if (used1[x] > used1[num] + a[num])
                    used1[x] = used1[num] + a[num];
                if (used1[x] > used2[num])
                    used1[x] = used2[num];
                if (used2[x] > used1[num] + a[num] * 2)
                    used2[x] = used1[num] + a[num] * 2;
                if (used2[x] > used2[num] + a[num])
                    used2[x] = used2[num] + a[num];
                st.insert({{used1[x], used2[x]}, x});
            }
        }
    }
    if (used1[n - 1] == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << used1[n - 1] << endl;
    return 0;
}