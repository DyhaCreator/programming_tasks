#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int a, b;
    cin >> a >> b;
    int y = 0;
    while ((a & (1 << y)) == (b & (1 << y)))
        y++;
    cout << (1 << y) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}