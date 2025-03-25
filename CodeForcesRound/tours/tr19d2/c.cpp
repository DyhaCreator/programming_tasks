#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt0 = 0;
    int cnt1 = 0;
    for (auto &x : a) {
        if (x == '0') cnt0++;
        else cnt1++;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int f = 1;
    for (int i = 0; i < n; i++) {

        if (f) {
            if (a[i] != b[i] && cnt0 != cnt1) {
                cout << "NO" << endl;
                return;
            }
            if (a[i] != b[i] && cnt0 == cnt1) {
                f = 0;
                swap(cnt0, cnt1);
            }
            if (f) {
                if (a[i] == '0') cnt0--;
                else cnt1--;
            } else {
                if (a[i] == '1') cnt0--;
                else cnt1--;
            }
        } else {
            if (a[i] == b[i] && cnt0 != cnt1) {
                cout << "NO" << endl;
                return;
            }
            if (a[i] == b[i] && cnt0 == cnt1) {
                f = 1;
                swap(cnt0, cnt1);
            }
            if (f) {
                if (a[i] == '0') cnt0--;
                else cnt1--;
            } else {
                if (a[i] == '1') cnt0--;
                else cnt1--;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}