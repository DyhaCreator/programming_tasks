#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll n, p;

ll f(ll m, vector<ll>&a, vector<ll>&b, vector<ll>&z) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (m <= z[i]) {
            sum += a[i] * m;
        } else {
            sum += a[i] * z[i] + b[i] * (m - z[i]);
        }
    }
    return sum;
}

int main() {
    cin >> n >> p;
    vector<ll>a(n);
    vector<ll>b(n);
    vector<ll>z(n);
    for (int i = 0; i < n; i++) {
        cin >> z[i] >> a[i] >> b[i];
    }
    ll l = 0;
    ll r = 10000000000000;
    for (int i = 0; i < 100; i++) {
        int m = (l + r) / 2;
        //cout << m << " " << f(m, a, b, z) << endl;
        if (f(m, a, b, z) < p) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << r << endl;
    return 0;
}