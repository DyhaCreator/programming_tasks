#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int solve() {
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= 2048) {
            sum += x;
        }
    }
    // sort(a.begin(), a.end());
    // cout << sum << endl;
    if (sum >= 2048) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}