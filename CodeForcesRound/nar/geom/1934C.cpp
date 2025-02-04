#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    cout << "? " << 1 << " " << 1 << endl;
    int d;
    cin >> d;
    if (d == 0) {
        cout << "! " << 1 << " " << 1 << endl;
        return;
    }
    cout << "? " << n << " " << 1 << endl;
    int a;
    cin >> a;
    cout << "? " << 1 << " " << m << endl;
    int b;
    cin >> b;
    cout << "? " << a - (n - d) << " " << 0 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}