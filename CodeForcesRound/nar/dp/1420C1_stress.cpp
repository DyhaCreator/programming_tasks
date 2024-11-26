#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int size = 20;
    for (int i = 0; i < 10; i++) {
        vector<ll> a = {};
        for (int j = 0; j < size; j++)
            a.push_back(rand() % 10);
        int mxx = 0;
        int mxK = 0;
        for (int k = 0; k < (1 << size); k++) {
            int z = 0;
            int th = 1;
            for (int j = 0; j < size; j++) {
                if ((k & (1 << j)) > 0) {
                    z += a[j] * th;
                    th = -th;
                }
            }
            // cout << z << endl;
            if (z > mxx) {
                mxx = z;
                mxK = k;
            }
            // cout << mxx << endl;
        }
        int n = size;
        reverse(a.begin(), a.end());
        vector<ll> dp(n);
        dp[0] = a[0];
        dp[1] = a[1];
        int mx = 0;
        int mn = 1;
        int j = 0;
        if (dp[j] < dp[1]) j = 1;
        for (int i = 2; i < n; i++) {
            dp[i] = max(a[i], a[i] - a[mn] + dp[mx]);
            if (dp[mx] - a[mn] < dp[j] - a[i]) {
                mx = j;
                mn = i;
            }
            if (dp[i] > dp[j]) j = i;
        }
        ll ans = 0;
        for (auto &x : dp)
            ans = max(ans, x);

        if (mxx != ans) {
            cout << ans << " " << mxx << " " << mxK << endl;
            for (auto &x : a)
                cout << x << " ";
            cout << endl;
        }

    }
    return 0;
}