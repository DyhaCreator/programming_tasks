#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

vector<int> xxx(3 * 1e5 + 10);

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = a;
    int x = xxx[a - 1];
    // cout << x << endl;
    // cout << ans << endl;
    if ((x ^ b) == a) {
        ans += 2;
    } else if ((x ^ b) != 0) {
        ans++;
    }
    cout << ans << endl;
}

int main() {
    int x = 0;
    int i = 0;
    for (auto &y : xxx) {
        x = x ^ i;
        y = x;
        i++;
    }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}