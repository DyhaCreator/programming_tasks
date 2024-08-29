#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n, k, m;
    cin >> n >> k >> m;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    ll sum = 0;
    bool find = false;
    for (int i = 0; i <= k; i++)
        sum += a[i];
    if (sum == m) {
        find = true;
        cout << 1 << endl;
        return 0;
    }
    // cout << sum << " ";
    for (int i = 0; i <= n - k; i++) {
        sum -= a[i];
        sum += a[i + k + 1];
        if (sum == m) {
            find = true;
            cout << i + 2 << endl;
            break;
        }
    }
    if (!find) cout << 0 << endl;
    return 0;
}