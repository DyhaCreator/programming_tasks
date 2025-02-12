#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    map<int, int> mp;
    for (int i = 0; i < m; i++)
        mp[b[i]] = i + 1;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] == 0) c[i] = INF; 
        else c[i] = mp[a[i]];
    }
    vector<int> d(n + 1);
    d[0] = -INF;
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    for (int i = 0; i < n; i++) {
        int j = int(upper_bound(d.begin(), d.end(), c[i]) - d.begin());
        if (d[j - 1] < c[i] && c[i] < d[j])
            d[j] = c[i];
    }
    ll mx = 0;
    for (ll i = 0; i <= n; i++) {
        if (d[i] != INF) {
            mx = i;
        }
    }
    cout << n - mx + m - mx << endl;
    return 0;
}