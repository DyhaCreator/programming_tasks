#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a = {};
    for (int i = 0; i < 10; i++) {
        a.push_back(n % 10);
        n /= 10;
    }
    int ans = (a[0] + 3) % 10;
    int z = 0;
    if (a[0] != 0) z = 1;
    for (int i = 1; i < 10; i++) {
        cout << ((7 - a[i]<0)?(17 - a[i]):7-a[i]) << " ";
        if (z == 0 && a[i] == 8) {
            ans = min(ans, 1);
        }
        if (a[i] != 7) {
            if (i == 1 && ((7 - a[i]<0)?(17 - a[i]):7-a[i]) > a[i - 1]) {
                ans = min(ans, ((7 - a[i]<0)?(17 - a[i]):7-a[i]) + 1);
            } else {
                if (z == 0) {
                    ans = min(ans, ((7 - a[i]<0)?(17 - a[i]):7-a[i]) + 1);
                } else {
                    ans = min(ans, ((7 - a[i]<0)?(17 - a[i]):7-a[i]));
                }
            }
        } else {
            ans = 0;
            break;
        }
        if (a[i] != 0) z = 1;
    }
    cout << endl;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}