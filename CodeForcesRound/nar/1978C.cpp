#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;
    if (m % 2 == 1) {
        cout << "No" << endl;
        return;
    }
    ll max_sum = 0;
    for (int i = 0; i < n; i++) {
        max_sum += abs(n - i - (i + 1));
    }
    if (m > max_sum) {
        cout << "No" << endl;
        return;
    }
    cout << "YES" << endl;
    // cout << max_sum << endl;
    int len = 0;
    ll sum = 0;
    while (sum < m) {
        sum += (n - len * 2 - 1) * 2;
        // cout << sum << endl;
        len++;
    }
    if (sum > m) {
        len--;
        sum -= (n - len * 2 - 1) * 2;
    }
    m -= sum;
    // cout << len << " " << sum << " " << m << endl;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    for (int i = 0; i < len; i++) {
        a[i] = n - i;
        a[n - i - 1] = i + 1;
    }
    if (m > 0) {
        a[len + m / 2] = len + 1;
        a[len] = len + m / 2 + 1;
    }
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}