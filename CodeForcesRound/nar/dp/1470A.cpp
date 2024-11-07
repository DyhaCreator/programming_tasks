#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    a.push_back(m + 1);
    b.push_back(0);
    vector<ll> dp(n + 1);
    dp[0] = 0;
    dp[1] = b[0];
    cout << b[0] << endl;
    vector<ll> dpIndex(n + 1);
    vector<ll> dpBin(n + 1);
    dpIndex[0] = 0;
    dpIndex[1] = 1;
    int last = 0;
    for (int i = 2; i <= n + 1; i++) {
        ll c1 = dp[i - 1] + b[dpIndex[i - 1]];
        ll c2 = dp[i - 1] - b[dpIndex[i - 2]] + b[a[i - 2] - 1] + b[dpIndex[i - 1] - 1];
        if (last) {
            c2 += b[dpIndex[i - 2]];
            c2 -= b[dpIndex[i - 1] - 1];;
        }
        cout << c1 << " " << c2 << "  " << dp[i - 1] << " " << -b[dpIndex[i - 2]] << " " << b[a[i - 2] - 1] << " " << b[dpIndex[i - 1] - 1] << endl;
        if (c1 < c2 && i <= m + 1) {
            dp[i] = c1;
            dpIndex[i] = dpIndex[i - 1] + 1;
            last = 0;
        } else {
            dp[i] = c2;
            dpIndex[i] = dpIndex[i - 1];
            last = 1;
        }
    }
    for (auto &x : dp)
        cout << x << " ";
    cout << endl;
    for (auto &x : dpIndex)
        cout << x << " ";
    cout << endl;
    for (auto &x : dpBin)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}