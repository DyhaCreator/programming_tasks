#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) a[i] = (s[i] - '0') - 1;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    map<int, int> mp;
    ll ans = 0;
    mp[0] = 1;
    for (int i = 1; i <= n; i++) {
        ans += mp[pref[i]];
        mp[pref[i]]++;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}