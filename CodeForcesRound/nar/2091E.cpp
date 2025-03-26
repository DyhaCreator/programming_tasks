#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<int> prime = {};

bool isPrime(int n) {
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    int index = 0;
    while (index < prime.size()) {
        int l = index;
        int r = prime.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (n / prime[m] <= n / prime[index]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        ans += (r - index) * (n / prime[index]);
        index = r;
    }
    cout << ans << endl;
}

int main() {
    vector<int> c(10000001, 0);
    for (int i = 2; i < c.size(); i++) {
        if (c[i] == 0) {
            int y = 2;
            while (i * y < c.size()) {
                c[i * y] = 1;
                y++;
            }
        }
    }
    for (int i = 2; i < c.size(); i++) {
        if (c[i] == 0) {
            prime.push_back(i);
        }
    }
    reverse(prime.begin(), prime.end());
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}