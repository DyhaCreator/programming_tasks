#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a ^ b ^ c) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}