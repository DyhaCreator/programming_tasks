#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int save_n = n;
    int len = 0;
    while (n > 1) {
        n /= 2;
        len++;
    }
    n = save_n;
    cout << n - (n - (1 << len)) - 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}