#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    int y = 0;
    while (k > (n - (1 << y)) / (1 << (y + 1)) + 1) {
        k -= (n - (1 << y)) / (1 << (y + 1)) + 1;
        y++;
    }
    cout << k * (1 << y) * 2 - (1 << y) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}