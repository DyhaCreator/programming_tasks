#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<ll> primeN = {};

int main() {
    ll n, d;
    cin >> n >> d;
    ll y = 0;
    while (y * y <= n + d + 1)
        y++;
    vector<ll> prime(y);
    for (ll i = 2; i * i <= y; i++) {
        if (prime[i] == 0) {
            ll z = 2;
            while (i * z < y) {
                prime[i * z] = 1;
                z++;
            }
        }
    }
    for (ll i = 2; i < y; i++) {
        if (prime[i] == 0) {
            primeN.push_back(i);
        }
    }
    vector<int> pr(d * 2 + 1, 1);
    for (int i = 0; i <= d - n; i++)
        pr[i] = 0;
    for (auto &x : primeN) {
        ll z = max((n - d * 2), 0LL) / x + 2;
        while (x * z <= n + d + 1) {
            if (x * z >= n - d) {
                pr[x * z - (n - d)] = 0;
            }
            z++;
        }
    }
    for (auto &x : primeN) {
        if (x * x >= n - d && x * x <= n + d) {
            pr[x * x - (n - d)] = 1;
        }
    }
    ll ans = 0;
    for (auto &x : pr)
        ans += x;
    cout << ans << endl;
    return 0;
}