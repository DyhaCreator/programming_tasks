#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    a.push_back(-1);
    vector<int> dp(n / 2 + 1, 0);
    for (int i = 0; i < n - 1; i++)
        if (a[i] == a[i + 1]) dp[0]++;
    int buff = a[0];
    a[0] = a[n - 1];
    a[n - 1] = buff;
    for (int i = 0; i < n - 1; i++)
        if (a[i] == a[i + 1]) dp[1]++;
    buff = a[0];
    a[0] = a[n - 1];
    a[n - 1] = buff;

    for (int i = 1; i < n / 2; i++) {
        int j = n - i - 1;
        int ca = 0;
        if (a[i] == a[i - 1]) ca++;
        if (a[i] == a[i + 1]) ca++;
        if (a[j] == a[j - 1]) ca++;
        if (a[j] == a[j + 1]) ca++;
        buff = a[i - 1];
        a[i - 1] = a[n - i];
        a[n - i] = buff;
        int cb = 0;
        if (a[i] == a[i - 1]) cb++;
        if (a[i] == a[i + 1]) cb++;
        if (a[j] == a[j - 1]) cb++;
        if (a[j] == a[j + 1]) cb++;
        buff = a[i - 1];
        a[i - 1] = a[n - i];
        a[n - i] = buff;
        buff = a[i];
        a[i] = a[j];
        a[j] = buff;
        int ca2 = 0;
        if (a[i] == a[i - 1]) ca2++;
        if (a[i] == a[i + 1]) ca2++;
        if (a[j] == a[j - 1]) ca2++;
        if (a[j] == a[j + 1]) ca2++;
        buff = a[i - 1];
        a[i - 1] = a[n - i];
        a[n - i] = buff;
        int cb2 = 0;
        if (a[i] == a[i - 1]) cb2++;
        if (a[i] == a[i + 1]) cb2++;
        if (a[j] == a[j - 1]) cb2++;
        if (a[j] == a[j + 1]) cb2++;
        // cout << ca << " " << ca2 << "  " << cb << " " << cb2 << endl;
        buff = a[i];
        a[i] = a[j];
        a[j] = buff;
        dp[i + 1] = min(dp[i] - (cb - cb2), dp[i - 1] - (ca - ca2));
    }
    int ans = INF;
    for (auto &x : dp)
        ans = min(ans, x);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}