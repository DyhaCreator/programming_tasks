#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

bool f(int n, int mxcnt, double a) {
    double b = a;
    int cnt = 0;
    while (b < n) {
        b += a;
        cnt++;
    }
    if (b == n && cnt <= mxcnt - 3)
        return 1;
    return 0;
}

void solve() {
    int n;
    cin >> n;
    int n_i = 3;
    while (f(n, n_i, (180.0 / n_i)) == 0)
        n_i++;
    cout << n_i << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}