#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (i + j) % 2 << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}