#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> count(14, vector<ll>(10));
    vector<vector<ll>> pref(14, vector<ll>(11));
    count[0][4] = 1;
    ll sum = 0;
    ll newSum = 0;
    ll mult = 1;
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 10; j++) {
            count[i][j] = sum;
            if (j == 4) {
                count[i][j] = mult;
                mult *= 10;
            }
            newSum += count[i][j];
            pref[i][j + 1] = newSum;
        }
        sum = newSum;
        newSum = 0;
    }
    for (auto &x : pref) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    ll q = 0;
    ll save = n;
    ll lst = 0;
    while (lst != n) {
        lst = n;
        ll ans = (n % 10 == 4);
        int index = 0;
        ll last = 0;
        while (n > 0) {
            if (n % 10 == 4) {
                ans += pref[index][n % 10] + last + index;
                cout << pref[index][n % 10] << " " << last << " " << index << endl;
            } else {
                ans += pref[index][n % 10];
            }
            cout << last << " " << n % 10 << " " << ans << endl;
            last = n % 10;
            n /= 10;
            index++;
        }
        n = save + ans;
        cout << n << endl;
        q++;
        if (q > 3) break;
    }
    cout << n << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}