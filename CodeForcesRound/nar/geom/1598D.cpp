#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int a1, b1;
        cin >> a1 >> b1;
        a[i] = a1;
        b[i] = b1;
    }
    map<int, ll> mpA;
    map<int, ll> mpB;
    for (int i = 0; i < n; i++) {
        mpA[a[i]]++;
        mpB[b[i]]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += (mpA[a[i]] - 1) * (mpB[b[i]] - 1);
    cout << n * (n - 1) * (n - 2) / 6 - ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}