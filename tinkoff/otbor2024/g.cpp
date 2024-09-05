#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    vector<ll> g(2 * n, -1);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        g[a - 1] = b - 1;
        g[b - 1] = a - 1;
    }
    ll plus = g[0];
    for (int i = 0; i < 2 * n; i++) {
        if ((i + g[i]) % (2 * n) != plus) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}