#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = 1e17 + 7;
int n;


int f(vector<ll> &a, ll x, ll sum) {
    sum += a[n - 1] + x;
    // cout << x << " " << sum << " ";
    int index = 0;
    double av = (double)sum / (double)n / 2.0;
    // cout << av << endl;
    a[n - 1] += x;

    int l = 0;
    int r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] < av) {
            l = m + 1;
        } else {
            r = m;
        }
        // cout << l << " " << r << endl;
    }
    a[n - 1] -= x;
    // cout << r << endl;
    return r;
}

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    ll sum = 0;
    for (int i = 0; i < n - 1; i++)
        sum += a[i];
    ll l = 0;
    ll r = INF;
    while (l < r) {
        ll m = (l + r) / 2;
        if (f(a, m, sum) <= n / 2) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (r == INF) {
        cout << - 1 << endl;
        return;
    }
    cout << r << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}