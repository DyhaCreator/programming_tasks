#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<ll>> m0(n, vector<ll>(n + 1));
    /*vector<vector<ll>> m1(n + 1);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            m0[i][j + 1] = m0[i][j] + (a[j] < a[i]);
            m1[j + 1] = m1[j];
            if (a[j] > a[i]) m1[j + 1].push_back(j);
            for (auto &x : m1[j])
                ans += m0[j][x];
            cout << ans << " ";
        }
        cout << endl;
        ans = 0;
    }*/
    vector<ll> m1(n + 1);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            m0[i][j + 1] = m0[i][j] + (a[j] < a[i]);
            m1[j + 1] = m1[j];
            if (a[j] > a[i]) m1[j + 1] += m0[j][j];
        }
        for (int j = 0; j < i; j++)
            cout << m1[j + 1] << " ";
        cout << endl;
        ans = 0;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}