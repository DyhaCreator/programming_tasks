#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = 1e10 + 7;
const int len = 256;

int res(int l, int r, vector<ll> &dec, vector<ll> &add, vector<ll> &a) {
    ll ans = 0;
    for (int i = l; i <= r;) {
        if (i % len == 0 && i + len <= r) {
            ans = max(dec[i / len], ans);
            i += len;
        } else {
            ans = max(ans, a[i] + add[i / len]);
            i++;
        }
    }
    return ans;
}

void upd(int l, int r, int x, vector<ll> &dec, vector<ll> &add, vector<ll> &a) {
    for (int i = l; i <= r;) {
        if (i % len == 0 && i + len <= r) {
            add[i / len] += x;
            dec[i / len] = max(dec[i / len], dec[i / len] + x);
            i += len;
        } else {
            a[i] += x;
            dec[i / len] = max(dec[i / len], a[i]);
            i++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> dec(n / len + 1, -INF);
    vector<ll> add(n / len + 1);
    for (auto &x : a)
        cin >> x;
    for (int i = 0; i < n; i++)
        dec[i / len] = max(a[i], dec[i / len]);
    
    int m;
    cin >> m;
    for (int q = 0; q < m; q++) {
        char w;
        cin >> w;
        if (w == 'm') {
            int l, r;
            cin >> l >> r;
            cout << res(l - 1, r - 1, dec, add, a) << " ";
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            upd(l - 1, r - 1, x, dec, add, a);
        }
    }
    cout << endl;
    return 0;
}