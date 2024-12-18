#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(3, vector<int> (n));
    for (auto &x : a)
        for (auto &y : x)
            cin >> y;
    ll tot = 0;
    for (auto &x : a[0])
        tot += x;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i != j && j != k && i != k) {
                    // cout << i << " " << j << " " << k << endl;
                    ll sum = 0;
                    ll index = 0;
                    while (index < n && sum < (tot + 2) / 3) {
                        sum += a[i][index];
                        index++;
                    }
                    if (sum < (tot + 2) / 3) {
                        break;
                    }
                    int l = index;
                    sum = 0;
                    while (index < n && sum < (tot + 2) / 3) {
                        sum += a[j][index];
                        index++;
                    }
                    if (sum < (tot + 2) / 3) {
                        break;
                    }
                    int r = index;
                    sum = 0;
                    while (index < n && sum < (tot + 2) / 3) {
                        sum += a[k][index];
                        index++;
                    }
                    if (sum >= (tot + 2) / 3) {
                        vector<pair<int, int>> ans(3);
                        ans[i] = {1, l};
                        ans[j] = {l + 1, r};
                        ans[k] = {r + 1, index};
                        cout << ans[0].first << " " << ans[0].second << " ";
                        cout << ans[1].first << " " << ans[1].second << " ";
                        cout << ans[2].first << " " << ans[2].second << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}