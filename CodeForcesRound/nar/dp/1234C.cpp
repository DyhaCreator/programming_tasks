#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        if (s1[i] > '2') a[i] = 1;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        if (s2[i] > '2') b[i] = 1;

    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (dp[i] == 1) {
            if (a[i] == 0) {
                dp[i + 1] = 1;
            } else if (a[i] == 1 && b[i] == 1) {
                dp[i + 1] = 2;
            } else if (a[i] == 1 && b[i] == 0) {
                dp[i + 1] = 0;
            }
        } else if (dp[i] == 2) {
            if (b[i] == 0) {
                dp[i + 1] = 2;
            } else if (b[i] == 1 && a[i] == 1) {
                dp[i + 1] = 1;
            } else if (b[i] == 1 && a[i] == 0) {
                dp[i + 1] = 0;
            }
        }
    }
    if (dp[n] == 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- ) solve();
    return 0;
}