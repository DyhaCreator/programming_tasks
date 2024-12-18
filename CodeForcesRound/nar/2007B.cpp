#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
const int len = 256;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
    vector<int> dec(n / len + 1);
    for (int i = 0; i < n; i++)
        if (a[dec[i / len]] < a[i]) dec[i / len] = i;
    for (int i = 0; i < n; i++) {
        char ch;
        int l, r;
        cin >> ch >> l >> r;
        l--;r--;
        if (ch == '+') {
            for (int i = l; i <= r; i++) {
                if (i % len == 0 && i + len <= r) {
                    i += len;
                } else {
                    a[i]++;
                    if (a[dec[i / len]] < a[i]) dec[i / len] = i;
                    i++;
                }
            }
        } else {
            for (int i = l; i <= r; i++) {
                if (i % len == 0 && i + len <= r) {
                    dec[i / len]--;
                    i += len;
                } else {
                    a[i]--;
                    if (i == dec[i / len]) {
                        for (int j = i; j < i + len - 1; j++) {
                            if (a[dec[j / len]] < a[j]) dec[j / len] = j;
                        }
                    }
                    i++;
                }
            }
        }
        for (auto &x : dec)
            cout << x << " ";
        cout << endl;
        for (auto &x : a)
            cout << x << " ";
        cout << endl;
        int ans = -INF;
        for (int i = 0; i <= n / len; i++)
            ans = max(ans, dec[i]);
        cout << a[ans] << "\n";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}