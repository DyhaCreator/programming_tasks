using namespace std; 
#include <iostream> 
#include <vector> 
using ll = long long; 
using vll = vector<ll>; 
const int len = 256;
const ll INF = 1e10 + 7; 

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> dec(n / len + 1, -INF); 
    vector<ll> add(n / len + 1, 0); 
    vector<ll> add_one(n, 0); 
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
        dec[i / len] = max(dec[i / len], a[i]); 
    }
    ll m;  
    cin >> m; 
    for (int q = 0; q < m; q++) { 
        ll l, r; 
        char st; 
        cin >> st >> l >> r;
        l--;r--;
        if (st == 'm') { 
            ll ans = -INF; 
            for (int i = l; i <= r;) { 
                if (i % len == 0 && i + len <= r) { 
                    ans = max(ans, dec[i/len]); 
                    i += len; 
                } else { 
                    ans = max(ans, a[i] + add_one[i] + add[i / len]); 
                    i++; 
                } 
            } 
            cout << ans << " ";
        } else {
            int x;
            cin >> x; 
            for (int i = l; i <= r;) { 
                if (i % len == 0 && i + len <= r) { 
                    add[i / len] += x; 
                    dec[i / len] += x;
                    i += len; 
                } else {
                    add_one[i] += x; 
                    dec[i / len] = max(dec[i / len], a[i] + add_one[i] + add[i / len]);
                    i++; 
                } 
            } 
        }
    } 
    return 0; 
}