#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n % 1000000007 << endl;
        return;
    }
    ll a = 1;
    ll b = 1;
    ll index = 1;
    while (a % k != 0) {
        a = (a + b) % k;
        swap(a, b);
        index++;
    }
    cout << ((index % 1000000007) * (n % 1000000007)) % 1000000007 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}