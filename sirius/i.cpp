#include <iostream>
#include <vector>
#define ll long long
#define INF 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        a[i] = A;
        b[i] = B;
        c[i] = C;
    }
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        int min = a[i - 1] + dp[i - 1];
        if (i > 1 && min > b[i - 2] + dp[i - 2]) {
            min = b[i - 2] + dp[i - 2];
        }
        if (i > 2 && min > c[i - 3] + dp[i - 3]) {
            min = c[i - 3] + dp[i - 3];
        }
        dp[i] = min;
        // cout << min << " ";
    }
    // cout << endl;
    cout << dp[n] << endl;
    return 0;
}