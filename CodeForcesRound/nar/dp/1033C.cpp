#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++)
        b[i] = {a[i], i};
    sort(b.rbegin(), b.rend());
    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++) {
        int f = 0;
        int index = b[i].S;
        while (index < n) {
            if (a[index] > a[b[i].S] && dp[n - a[index]] == 0) f = 1;
            index += b[i].F;
        }
        index = b[i].S;
        while (index >= 0) {
            if (a[index] > a[b[i].S] && dp[n - a[index]] == 0) f = 1;
            index -= b[i].F;
        }
        if (f) {
            dp[i] = 1;
        } else {
            dp[i] = 0;
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[b[i].S] = dp[i];
    for (auto &x : ans)
        cout << ((x)?"A":"B");
    cout << endl;
    return 0;
}