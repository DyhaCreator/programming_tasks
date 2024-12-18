#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll>a = vector<ll>(n);
    for (auto &x : a)
        cin >> x;
    vector<ll>pref = vector<ll>(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    ll ans = 0;
    ll min_sum = 0;
    int len = 0;
    int max_len = 0;
    for (int r = 1; r <= n; r++) {
        len++;
        ll sum = pref[r];
        if (sum - min_sum - (len / k * x) > ans) {
            ans = sum - min_sum - (len / k * x);
            max_len = len;
        }
        if (sum < min_sum) {
            min_sum = sum;
            len = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
/*

6 3 8
1 -3 14 -2 9 4

5 5 5
-1 -2 -3 -4 -10

4 2 5
6 6 -9 7

*/