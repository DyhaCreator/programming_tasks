#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : a)
        x = x % m;
    set<int> st;
    map<int, int> mp;
    for (auto &x : a) {
        st.insert(x);
        mp[x]++;
    }
    for (auto &x : st) {
        if (mp[x] >= m || x == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    vector<int> dp0(m, 0);
    vector<int> dp1(m, 0);
    vector<int> dp2(m, 0);
    dp1[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp2[(j + a[i]) % m] = max(dp2[(j + a[i]) % m], dp0[j]);
            dp2[(j + a[i]) % m] = max(dp2[(j + a[i]) % m], dp1[j]);
            if (j > 0) {
                dp2[j] = max(dp2[j], dp0[j]);
                dp2[j] = max(dp2[j], dp1[j]);
            }
        }

        dp2[a[i]] = 1;
        if (dp2[0] == 1) {
            cout << "YES" << endl;
            return 0;
        }
        /*for (auto &x : dp2)
            cout << x << " ";
        cout << endl;*/
        dp0 = dp1;
        dp1 = dp2;
        dp2 = vector<int>(m, 0);
    }
    cout << "NO" << endl;
    return 0;
}