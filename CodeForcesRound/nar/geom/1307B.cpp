#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans = min(ans, ((m < a)?2:(m + a - 1) / a));
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}