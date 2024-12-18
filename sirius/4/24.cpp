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
    int j = 1;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        while (a[i] - a[j] > k) {
            j++;
        }
        // cout << j - 1 << " " << i << " " << a[i] - a[j - 1] << endl;
        if (a[i] - a[j - 1] > k) {
            ans += j;
        }
    }
    cout << ans << endl;
    return 0;
}