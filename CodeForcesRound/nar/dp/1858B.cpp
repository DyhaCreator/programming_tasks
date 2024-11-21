#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    m += 2;
    vector<int> a(m);
    a[0] = 1;
    a[m - 1] = n + 1;
    for (int i = 1; i < m - 1; i++)
        cin >> a[i];
    vector<int> pref(m);
    for (int i = 1; i < m; i++)
        pref[i] = pref[i - 1] + (a[i] - a[i - 1] + d - 1) / d;
    int ans = INF;
    int count = 1;
    for (int i = 1; i < m - 1; i++) {
        int th = pref[i - 1] + pref[m - 1] - pref[i + 1] + (a[i + 1] - a[i - 1] + d - 1) / d;
        // cout << -a[i] << " " << pref[i - 1] + pref[m - 1] - pref[i + 1] + (a[i + 1] - a[i - 1] + d - 1) / d << endl;
        if (ans == th) {
            count++;
        } else if (ans > th) {
            count = 1;
        }
        ans = min(ans, th);
    }
    cout << ans << " " << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}