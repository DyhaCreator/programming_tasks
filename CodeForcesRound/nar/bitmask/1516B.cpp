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
        pref[i + 1] = pref[i] ^ a[i];
    if (pref[n] == 0) {
        cout << "YES" << endl;
        return;
    }
    /*for (auto &x : pref)
        cout << x << " ";
    cout << endl;*/
    int f = 0;
    vector<int> pr(n + 1);
    for (int i = 0; i < n; i++)
        pr[i + 1] = pr[i] + ((pref[i + 1] == 0)?1:0);
    for (int i = 0; i < n - 1; i++) {
        if (pref[i] == pref[n] && pr[n] - pr[i] > 0) f = 1;
    }
    if (f) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}