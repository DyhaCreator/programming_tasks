#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    ll mx = 0;
    for (auto &x : a)
        mx = max(mx, x);
    ll f = 1;
    ll s = 2;
    map<ll, ll> mp;
    while (s <= mx * 2) {
        mp[f] = 1;
        mp[s] = 1;
        f += s;
        ll buff = f;
        f = s;
        s = buff;
    }
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++)
        b[i] = {a[i], i};
    sort(b.rbegin(), b.rend());
    vector<int> used(n);
    vector<pair<int, int>> ans = {};
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            if (mp[b[l].F + b[r].F] == 1 && used[l] == 0 && used[r] == 0) {
                used[r] = 1;
                used[l] = 1;
                ans.push_back({b[r].S, b[l].S});
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto &x : ans)
        cout << x.F + 1 << " " << x.S + 1 << endl;
    return 0;
}