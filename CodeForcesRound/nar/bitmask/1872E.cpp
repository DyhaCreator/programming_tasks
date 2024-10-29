#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = a[i] ^ pref[i];
    string s;
    cin >> s;
    int x0 = 0;
    int x1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') x0 = x0 ^ a[i];
        else x1 = x1 ^ a[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            int l, r;
            cin >> l >> r;
            x0 = x0 ^ (pref[l - 1] ^ pref[r]);
            x1 = x1 ^ (pref[l - 1] ^ pref[r]);
        } else {
            int g;
            cin >> g;
            cout << ((g == 0)?x0:x1) << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}