#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int mn = k;
    int mx = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < mn) {
            mn -= a[i];
            mx += a[i];
        } else if (a[i] == mn) {
            mn = k;
            mx = 0;
            ans++;
        } else if (a[i] > mn && a[i] < k) {
            a[i] -= mn;
            mx = a[i];
            mn = k - a[i];
            ans++;
        } else if (a[i] >= k) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}