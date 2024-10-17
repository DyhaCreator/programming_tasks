#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> b(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        b[i] = (INF + a[i] - 1) / a[i];
        sum += b[i];
    }
    if (sum < INF) {
        for (auto &x : b)
            cout << x << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}