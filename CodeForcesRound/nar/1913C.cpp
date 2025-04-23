#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> m(30, 0);
    for (int i = 0; i < n; i++) {
        ll t, a;
        cin >> t >> a;
        if (t == 1) {
            m[a]++;
        } else {
            vector<ll> b(30);
            for (int j = 0; j < 30; j++) {
                b[j] = a % 2;
                a /= 2;
            }
            /*for (auto &x : m)
                cout << x << " ";
            cout << endl;
            for (auto &x : b)
                cout << x << " ";
            cout << endl;*/
            int f = 0;
            int ost = 0;
            for (int j = 0; j < 30; j++) {
                ost += m[j];
                if (ost >= b[j]) {
                    ost -= b[j];
                } else {
                    f = 1;
                    cout << "NO" << endl;
                    break;
                }
                ost /= 2;
            }
            if (f == 0) {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}