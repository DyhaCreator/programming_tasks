#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << min(n, k) * min(m, k) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}