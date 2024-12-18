#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll nn = 0;
    for (auto &x : a) {
        cin >> x;
        nn = nn | x;
    }
    int l = 1;
    int r = n;
    while (l < r) {
        int m = (l + r) / 2;
        int found = 0;
        vector<ll> num(31);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 31; j++) {
                if (a[i] & (1LL << j)) {
                    num[j]++;
                }
            }
            if (i >= m - 1) {
                if (i >= m) {
                    for (int j = 0; j < 31; j++) {
                        if (a[i - m] & (1LL << j)) {
                            num[j]--;
                        }
                    }
                }
                ll newNum = 0;
                for (int j = 30; j >= 0; j--) {
                    newNum = newNum << 1;
                    if (num[j] > 0) {
                        newNum++;
                    }
                }
                // cout << newNum << " ";
                if (newNum != nn) {
                    found = 1;
                }
                // cout << i << " " << m << endl;
            }
            /*for (auto &x : num)
                cout << x << " ";
            cout << endl;*/
        }
        // cout << endl;
        if (found) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << r << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}