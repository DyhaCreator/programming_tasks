#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> p(n + 1);
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];
    for (int len = n; len >= 0; len--) {
        for (int i = 0; i < n - len; i++) {
            // cout << i << " " << i + len << endl;
            if ((p[i + len + 1] - p[i]) % 3 == 0) {
                // cout << 111 << endl;
                cout << i + 1 << " " << i + len + 1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}