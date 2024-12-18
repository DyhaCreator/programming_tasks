#include <algorithm>
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
    sort(a.begin(), a.end());
    if (a[0] != 1) {
        cout << "NO" << endl;
        return;
    }
    ll sum = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > sum) {
            cout << "NO" << endl;
            return;
        }
        sum += a[i];
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}