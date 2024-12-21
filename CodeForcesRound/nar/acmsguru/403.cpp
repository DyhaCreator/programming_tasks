#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll x;
    cin >> x;
    ll l = 1;
    ll r = 2e9 + 10;
    while (l < r) {
        ll m = (l + r) / 2;
        if ((m * (m - 1) / 2) / m < x) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << r << endl;
    return 0;
}