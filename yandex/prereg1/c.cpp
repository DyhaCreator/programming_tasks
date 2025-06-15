#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll ans = 0;
    if (s[0] - 'a' + 1 == m) {
        cout << 0 << endl;
        return 0;
    }
    for (int k = 1; k < n; k++) {
        ll var = 1;
        for (int j = 0; j < k; j++)
            var *= m - (s[j] - 'a') - 1;
        var *= s[k] - 'a' + 1;
        for (int i = k + 1; i < n; i++)
            var *= m;
        cout << var << endl;
        ans += var;
        if (s[k] - 'a' + 1 == m)
            break;
    }
    cout << ans << endl;
    return 0;
}