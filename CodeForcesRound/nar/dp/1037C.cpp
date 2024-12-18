#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        if (a[i] == '1' && b[i] == '0') {
            c[i] = 1;
        } else if (a[i] == '0' && b[i] == '1') {
            c[i] = 2;
        }
    }
    vector<int> dp(n);
    int l1 = INF;
    int l2 = INF;
    vector<int> l(n, -1);
    for (int i = 0; i < n; i++) {
        if (c[i] == 1) {
            l[i] = l2;
            l1 = 0;
        } else if (c[i] == 2) {
            l[i] = l1;
            l2 = 0;
        }
        l1++;
        l2++;
    }
    dp[0] = (c[0] != 0);
    int isLast = 0;
    for (int i = 1; i < n; i++) {
        if (c[i] != 0) {
            if (dp[i - 1] - 1 + l[i] < dp[i - 1] + 1 && !isLast) {
                dp[i] = dp[i - 1] - 1 + l[i];
                isLast = 1;
            } else {
                dp[i] = dp[i - 1] + 1;
                isLast = 0;
            }
        } else {
            isLast = 0;
            dp[i] = dp[i - 1];
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}