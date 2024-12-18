#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    if ((1LL << k) <= n && k <= 32) {
        cout << (1LL << k) << endl;
    } else {
        cout << n + 1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}