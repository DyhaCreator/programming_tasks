#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int m1 = INF;
    int m2 = INF;
    int m3 = INF;
    for (int i = 0; i < n; i++) {
        int m, k;
        cin >> m >> k;
        if (k % 10 == 0 && k / 10 == 1) {
            m2 = min(m2, m);
        } else if (k % 10 == 1 && k / 10 == 0) {
            m1 = min(m1, m);
        } else if (k % 10 == 1 && k / 10 == 1) {
            m3 = min(m3, m);
        }
    }
    if ((m1 == INF || m2 == INF) && m3 == INF) {
        cout << -1 << endl;
        return;
    }
    cout << min(m1 + m2, m3) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}