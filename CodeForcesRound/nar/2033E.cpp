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
    for (auto &x : a)
        x--;
    vector<int> fnd(n);
    for (int i = 0; i < n; i++)
        fnd[a[i]] = i;
    vector<int> used(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != fnd[i]) {
            int ind = fnd[i];
            swap(a[a[i]], a[fnd[i]]);
            ans++;
            fnd[a[ind]] = ind;
            fnd[i] = a[i];
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}