#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (auto &x : a)
        cin >> x;
    vector<int> ans(n);
    ans[0] = a[0];
    for (int i = 1; i < n; i++)
        ans[i] = a[i - 1];
    for (int i = 1; i < n; i++)
        ans[i - 1] = ans[i - 1] | ans[i];
    for (int i = 1; i < n; i++) {
        // cout << (ans[i - 1] & ans[i]) << " " << a[i - 1] << "  ";
        if ((ans[i - 1] & ans[i]) != a[i - 1]) {
            cout << -1 << endl;
            return;
        }
    }
    // cout << endl;
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}