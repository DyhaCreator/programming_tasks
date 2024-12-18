#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += (n - i + 1) * (m - j + 1);
        }
    }
    cout << ans << endl;
    return 0;
}