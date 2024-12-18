#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct int2{
    ll x = 0, y = 0;
    int2() {}
    int2(ll x, ll y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << endl;
        return 0;
    }
    vector<int2>dp1 = vector<int2>(k, int2(1, 1));
    vector<int2>dp2 = vector<int2>(k);
    for (int y = 1; y < n; y++) {
        for (int x = 0; x < k; x++) {
            for (int i = 0; i < x; i++) {
                dp2[x].x += dp1[i].y;
            }
            for (int i = x + 1; i < k; i++) {
                dp2[x].y += dp1[i].x;
            }
            dp2[x].x = dp2[x].x % int(1e9 + 7);
            dp2[x].y = dp2[x].y % int(1e9 + 7);
            //cout << dp2[x].x << " " << dp2[x].y << endl;
        }
        //cout << endl;
        dp1 = dp2;
        dp2 = vector<int2>(k);
    }
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += (dp1[i].x + dp1[i].y) % int(1e9 + 7);
    }
    cout << ans << endl;
    return 0;
}