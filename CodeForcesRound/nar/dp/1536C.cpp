#include <iostream>
#include <vector>
#include <map>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int nod(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == 1 || b == 1) return 1;
    if (a < b) {
        int buff = a;
        a = b;
        b = buff;
    }
    while (a % b != 0) {
        a = a % b;
        int buff = a;
        a = b;
        b = buff;
    }
    return b;
}

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<pair<int, int>> dp(n + 1);
    vector<int> dpCount(n + 1);
    map<pair<int, int>, pair<int, int>> mp;

    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        if (a[i] == 'D') {
            dp[i + 1].F++;
        } else if (a[i] == 'K') {
            dp[i + 1].S++;
        }
        int nd = nod(dp[i + 1].F, dp[i + 1].S);
        int d = dp[i + 1].F / nd;
        int k = dp[i + 1].S / nd;
        // cout << dp[i + 1].F << " " << dp[i + 1].S << endl;
        // cout << d << " " << k << endl;
        if (mp[{d, k}].S) dpCount[i + 1] = dpCount[mp[{d, k}].F + 1] + 1;
        else dpCount[i + 1] = 1;
        mp[{d, k}] = {i, 1};
    }
    for (int i = 1; i <= n; i++)
        cout << dpCount[i] << " ";
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}