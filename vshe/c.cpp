#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
const int len = 2;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<int> cnt(k);
    for (auto &x : b)
        cnt[x - 1]++;
    for (int i = 0; i < m; i++)
        cnt[a[i] - 1]--;
    vector<int> c(k);
    vector<int> d(k);
    for (int i = 0; i < k; i++) {
        if (cnt[i] < 0) {
            c[i] = cnt[i];
        } else {
            d[i] = cnt[i];
        }
    }

    int cnt1 = 0;
    int cnt2 = 0;
    for (auto &x : c)
        cnt1 += x;
    for (auto &x : d)
        cnt2 += x;

    int ans = 0;
    for (int i = m; i < n; i++) {
        if (abs(cnt1 + cnt2) <= 1 && abs(cnt1) <= 1 && abs(cnt2) <= 1) {
            ans++;
        }
        if (c[a[i - m] - 1] == 0) {
            d[a[i - m] - 1]++;
            cnt2++;
        } else {
            c[a[i - m] - 1]++;
            cnt1++;
        }

        if (d[a[i] - 1] == 0) {
            c[a[i] - 1]--;
            cnt1--;
        } else {
            d[a[i] - 1]--;
            cnt2--;
        }

    }
    if (abs(cnt1 + cnt2) <= 1 && abs(cnt1) <= 1 && abs(cnt2) <= 1) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}