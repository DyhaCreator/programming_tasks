#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<ll >> dp1 = vector<vector<ll >> (k, vector<ll>(2, 1));
    vector<vector<ll >> dp2 = vector<vector<ll >> (k, vector<ll>(2, 0));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < j; l++) {
                dp2[j][0] = (dp2[j][0] + dp1[l][1]) % int(1e9 + 7);
            }
            for (int l = j + 1; l < k; l++) {
                dp2[j][1] = (dp2[j][1] + dp1[l][0]) % int(1e9 + 7);
            }
        }
        dp1 = dp2;
        dp2 = vector<vector<ll >> (k, vector<ll>(2, 0));
    }
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += dp1[i][0] + dp1[i][1];
    }
    if (n == 1) {
        cout << ans / 2 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}