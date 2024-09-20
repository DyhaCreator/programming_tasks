#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x - 1]++;
    }
    for (int i = 0; i < n; i++)
        if (a[m] < a[i]) m = i;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i != m) ans += a[i];
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}