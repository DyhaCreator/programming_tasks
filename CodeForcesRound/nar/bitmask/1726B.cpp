#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n > m) {
        cout << "NO" << endl;
        return;
    }
    if (n > 1 && n % 2 == 0 && m % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (n % 2 == 1) {
        for (int i = 0; i < n - 1; i++) {
            cout << 1 << ' ';
        }
        cout << m - (n - 1) << endl;
    } else {
        for (int i = 0; i < n - 2; i++) {
            cout << 1 << " ";
        }
        cout << (m - (n - 2)) / 2 << " " << (m - (n - 2)) / 2 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}