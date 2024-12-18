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
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    int j = 0;
    int bj = 0;
    int bi = 1;
    for (int i = 1; i <= n; i++) {
        if (pref[i] - pref[j] > pref[bi] - pref[bj]) {
            bi = i;
            bj = j;
        }
        if (pref[j] >= pref[i]) j = i;
    }
    if (pref[bi] - pref[bj] < pref[n]) {
        cout << "YES" << endl;
    } else if (bi == n && bj == 0) {
        if (a[0] == 0 || a[n - 1] == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}