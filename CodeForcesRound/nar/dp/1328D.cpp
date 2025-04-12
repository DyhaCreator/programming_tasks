#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int f1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != a[0]) f1 = 1;
    }
    if (f1 == 0) {
        cout << 1 << endl;
        for (auto &x : a)
            cout << 1 << " ";
        cout << endl;
        return;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = i % 2 + 1;
    if (n % 2 == 1) {
        int f = 0;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] == a[i]) {
                for (int j = i; j < n; j++)
                    ans[j] = (j + 1) % 2 + 1;
                f = 1;
                break;
            }
        }
        if (f == 0 && a[0] != a[n - 1])
            ans[n - 1] = 3;
    }
    int cnt = 0;
    for (auto &x : ans)
        cnt = max(cnt, x);
    cout << cnt << endl;
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}