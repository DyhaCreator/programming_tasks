#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << -1 << endl;
        return;
    }
    if (((n / 2) & n) != 0) {
        cout << -1 << endl;
        return;
    }
    cout << (n / 2) << " " << (n | (n / 2)) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}