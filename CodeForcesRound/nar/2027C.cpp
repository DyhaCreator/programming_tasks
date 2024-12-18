#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
ll n;
ll ans = 0;
map<ll, vector<ll>> mp;

void gen(vector<ll> &a, ll col) {
    for (auto &x : mp[col])
        if (a[x] == -1) {
            a[x] = 1;
            gen(a, col + x);
        }
    ans = max(ans, n + col);
}

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    mp.clear();
    for (int i = 1; i < n; i++)
        mp[a[i] - (n - i)].push_back(i);
    ans = 0;
    vector<ll> used(n, -1);
    gen(used, 0);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}