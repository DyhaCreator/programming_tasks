#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
ll ans = 0;

void dfs(ll v, ll s, ll len, vector<int> &used) {
    
}

void solve() {
    ll s, k;
    cin >> s >> k;
    if (s % k == 0) {
        cout << k << endl;
        return 0;
    } else if (s > k * k) {
        cout << k - 2 << endl;
    } else {
        ans = 0;
        vector<
        dfs(0, s, k, used);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}