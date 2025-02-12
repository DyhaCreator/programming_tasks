#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll w, h, n;
    cin >> w >> h >> n;
    ll l = 0;
    ll r = max(w, h) * n;
    while (l < r) {
        ll m = (l + r) / 2;
        if ((m / w) * (m / h) < n) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << r << endl;
    return 0;
}