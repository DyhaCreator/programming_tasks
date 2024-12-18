#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> as = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<int> sum_costs = {};
    vector<int> dp(n + 1, -INF);
    vector<int> pred(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (i - as[a[j]] >= 0 && dp[i - as[a[j]]] + 1 >= dp[i] && dp[i - as[a[j]]] != -INF) {
                dp[i] = dp[i - as[a[j]]] + 1;
                pred[i] = a[j];
            }
        }
    }
    if (pred[n] == 0) {
        // cout << pred[n] << endl;
        for (int i = 0; i < k; i++) {
            // cout << i << " " << a[i] << " " << pred[n - as[a[i]]] << endl;
            if (pred[n - as[a[i]]] != -INF && a[i] != 0) {
                pred[n] = a[i];
                break;
            }
        }
    }
    /*for (auto &x : dp)
        cout << x << " ";
    cout << endl;
    for (auto &x : pred)
        cout << x << " ";
    cout << endl;*/
    vector<int> ans = {};
    int index = n;
    while (pred[index] != -1) {
        ans.push_back(pred[index]);
        index = index - as[pred[index]];
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    // if (ans[0] == 0 && ans.size() > 1) cout << "hui" << endl;
    /*if (ans[0] == 0 && ans.size() > 1) {
        for (int i = 0; i < n / 7; i++)
            cout << 8;
        cout << endl;
        return 0;
    }*/
    for (auto &x : ans)
        cout << x << "";
    cout << endl;
    return 0;
}