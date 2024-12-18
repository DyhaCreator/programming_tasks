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
    vector<int> b(n);
    for (auto &x : b)
        cin >> x;
    int m1 = 0;
    int m2 = 0;
    int minus = 0;
    int plus = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            m1 += a[i];
        } else if (a[i] < b[i]) {
            m2 += b[i];
        } else {
            if (a[i] == -1) {
                minus++;
            } else if (a[i] == 1) {
                plus++;
            }
        }
    }
    // cout << plus << " " << minus << endl;
    for (int i = 0; i < plus; i++) {
        if (m1 < m2) {
            m1++;
        } else {
            m2++;
        }
    }
    for (int i = 0; i < minus; i++) {
        if (m1 > m2) {
            m1--;
        } else {
            m2--;
        }
    }
    cout << min(m1, m2) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}