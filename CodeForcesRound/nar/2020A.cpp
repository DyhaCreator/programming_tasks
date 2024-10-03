#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if (k == 1) {
        cout << n << endl;
        return;
    }
    while (n > 0) {
        ans += n % k;
        n /= k;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}