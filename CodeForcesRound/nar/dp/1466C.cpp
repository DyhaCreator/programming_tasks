#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    vector<ll> a(s.begin(), s.end());
    int n = s.size();
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int found = 0;
        if (a[i] == a[i - 1]) {
            while (a[i] == a[i - 1] || (i + 1 < n && a[i] == a[i + 1]) || (i - 2 >= 0 && a[i] == a[i - 2]) || (i + 2 < n && a[i] == a[i + 2]))
                a[i] = rand();
            found = 1;
        }
        if (i > 1 && a[i] == a[i - 2]) {
            while (a[i] == a[i - 1] || (i + 1 < n && a[i] == a[i + 1]) || (i - 2 >= 0 && a[i] == a[i - 2]) || (i + 2 < n && a[i] == a[i + 2]))
                a[i] = rand();
            found = 1;
        }
        ans += found;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}