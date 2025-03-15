#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void srt(vector<int> &a, ll &ans) {
    if (a.size() == 1) return;
    vector<int> c((a.size() + 1) / 2);
    vector<int> d(a.size() / 2);
    for (int i = 0; i < a.size(); i++) {
        if (i < (a.size() + 1) / 2) {
            c[i] = a[i];
        } else {
            d[i - (a.size() + 1) / 2] = a[i];
        }
    }
    srt(c, ans);
    srt(d, ans);

    for (auto &x : d) {
        int l = 0;
        int r = c.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (c[m] <= x) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        ans += c.size() - r;
    }

    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < a.size(); i++) {
        if (index1 < c.size() && index2 < d.size()) {
            if (c[index1] < d[index2]) {
                a[i] = c[index1];
                index1++;
            } else {
                a[i] = d[index2];
                index2++;
            }
        } else if (index1 < c.size()) {
            a[i] = c[index1];
            index1++;
        } else {
            a[i] = d[index2];
            index2++;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> cnt(n);
    for (auto &x : a)
        cnt[x - 1]++;
    ll ans = 0;
    for (auto &x : cnt)
        if (x > 0) ans += x * (x - 1) / 2;
    srt(a, ans);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}