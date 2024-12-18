#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll y = 0;
    while ((1LL << y) < k)
        y++;
    if ((1 << y) - 1 == k || k == 1) y++;
    y--;
    // cout << y << endl;
    // cout << (1 << y) - 1 << endl;
    if (n == 1) {
        cout << k << endl;
    } else {
        cout << (1 << y) - 1 << " " << k - ((1 << y) - 1) << " ";
        for (int i = 0; i < n - 2; i++)
            cout << 0 << " ";
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}