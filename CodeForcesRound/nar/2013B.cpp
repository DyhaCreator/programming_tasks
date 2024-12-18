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
    for (int i = 0; i < n - 2; i++) {
        a[n - 2] -= a[i];
    }
    cout << a[n - 1] - a[n - 2] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}