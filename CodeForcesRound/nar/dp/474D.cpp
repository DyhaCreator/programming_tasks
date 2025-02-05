#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll t, k;
    cin >> t >> k;
    vector<ll> dp(100011, 1);
    for (int i = max(k - 2, 0LL); i < 100010; i++)
        dp[i + 1] = (dp[i] + dp[max(i - k + 1, 0LL)]) % 1000000007;
    vector<ll> pref(100012);
    for (int i = 0; i < 100011; i++)
        pref[i + 1] = (pref[i] + dp[i]) % 1000000007;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        if (k == 1) {
            b++;
            a++;
        }
        cout << (pref[b] - pref[max(a - 1, 0)] + 1000000007) % 1000000007 << endl;
    }
    return 0;
}