#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    double sy = 0;
    double sx = 0;
    for (auto &x : a) {
        cin >> x.F >> x.S;
        sy += x.F;
        sx += x.S;
    }
    sy /= n;
    sx /= n;
    cout << sy << " " << sx << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}