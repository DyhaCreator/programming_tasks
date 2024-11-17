#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<ll> dp1(n);
    vector<ll> dp2(n);
    dp1[0] = a[0];
    dp2[0] = b[0];
    ll mx1 = a[0];
    ll mx2 = b[0];
    for (int i = 1; i < n; i++) {
        dp1[i] = mx2 + a[i];
        dp2[i] = mx1 + b[i];
        mx1 = max(mx1, dp1[i]);
        mx2 = max(mx2, dp2[i]);
    }
    cout << max(mx1, mx2) << endl;
    return 0;
}