#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

bool f(ll a, ll b) {
    for (ll i = 0; i < 32; i++) {
        if ((a & (1LL << i)) > 0 && (b & (1LL << i)) == 0) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    for (auto &x : c)
        cin >> x;
    ll countA = 0;
    ll countB = 0;
    ll countC = 0;
    ll index = 0;
    while (index < n && f(a[index], k)) {
        countA = countA | a[index];
        index++;
    }
    index = 0;
    while (index < n && f(b[index], k)) {
        countB = countB | b[index];
        index++;
    }
    index = 0;
    while (index < n && f(c[index], k)) {
        countC = countC | c[index];
        index++;
    }
    // cout << countA << " " << countB << " " << countC << endl;
    if ((countA | countB | countC) == k) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}