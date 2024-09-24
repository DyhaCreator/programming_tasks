#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if ((n + k - 1) / k > (m + k - 1) / k) {
        cout << max((n + k - 1) / k * 2 - 1, 0) << " "  << endl;
    } else {
        cout << (m + k - 1) / k * 2 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}