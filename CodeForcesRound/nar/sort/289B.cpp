#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    n *= m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : a)
        if (x % d != a[0] % d) {
            cout << -1 << endl;
            return 0;
        }
    sort(a.begin(), a.end());
    for (auto &x : a)
        x /= d;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    int ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, i * a[i] - (pref[i] - pref[0]) + (pref[n] - pref[i + 1]) - a[i] * (n - i - 1));
    cout << ans << endl;
    return 0;
}