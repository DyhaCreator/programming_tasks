#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> c(k + 1, vector<ll>(n + 1));
    c[1] = vector<ll>(n + 1, 1);
    c[1][0] = 0;
    for (int i = 2; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j + 1] = c[i][j] + c[i - 1][j];
        }
    }
    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        ll sum = 0;
        for (auto &x : c[i])
            sum += x;
        if (i == 3) ans += sum * 2;
        else if (i == 4) ans += sum * 9;
        else if (i == 1) ans += 0;
        else if (i == 0) ans += 1;
        else ans += sum;
    }
    cout << ans << endl;
    return 0;
}