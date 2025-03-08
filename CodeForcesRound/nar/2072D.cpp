#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int L = 0;
    int R = 0;
    int c = 0;
    for (int j = 0; j < n; j++) {
        vector<int> l(n + 1);
        vector<int> r(n + 1);
        for (int i = 0; i < n; i++) {
            l[i + 1] = l[i];
            if (a[i] > a[j])
                l[i + 1]++;
        }
        for (int i = n - 1; i >= 0; i--) {
            r[i] = r[i + 1];
            if (a[i] < a[j])
                r[i]++;
        }
        int mn = j;
        for (int i = j; i < n; i++) {
            if (l[i + 1] + r[i + 1] < l[mn + 1] + r[mn + 1]) {
                mn = i;
            }
        }
        if (l[j + 1] + r[j] - l[mn + 1] - r[mn + 1] > c) {
            L = j;
            R = mn;
            c = l[j + 1] + r[j] - l[mn + 1] - r[mn + 1];
        }
    }
    cout << L + 1 << " "  << R + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}