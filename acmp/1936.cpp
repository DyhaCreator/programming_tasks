#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> l(n);
    l[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            l[i] = l[i - 1] + 1;
        } else {
            l[i] = 1;
        }
    }
    vector<ll> r(n);
    r[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            r[i] = r[i + 1] + 1;
        } else {
            r[i] = 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += l[i] * r[i];
    cout << ans << endl;
    return 0;
}