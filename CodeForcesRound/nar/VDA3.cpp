#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<ll>a(n);
        vector<ll>b(m);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        sort(a.rbegin(), a.rend());
        sort(b.begin(), b.end());
        vector<ll>c(n + 1);
        vector<ll>d(n + 1);
        ll s = 0;
        for (int i = 0; i < n; i++) {
            s += abs(b[i] - a[i]);
            c[i + 1] = s;
        }
        s = 0;
        for (int i = n - 1; i >= 0; i--) {
            s += abs(b[m - n + i] - a[i]);
            d[i] = s;
        }
        reverse(d.begin(), d.end());
        /*for (auto &x : c)
            cout << x << " ";
        cout << endl;
        for (auto &x : d)
            cout << x << " ";
        cout << endl;*/
        ll mmm = 0;
        for (int k = 0; k <= n; k++) {
            ll ans = c[k] + d[n - k];
            if (ans > mmm) {
                mmm = ans;
            }
            //cout << c[k] << " " << d[n - k] << " " << ans << endl;
        }
        cout << mmm << endl;
    }
    return 0;
}