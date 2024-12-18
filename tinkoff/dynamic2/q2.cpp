#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, a1, k, b, m;
    cin >> n >> a1 >> k >> b >> m;
    vector<int>a = vector<int>(n);
    a[0] = a1;
    for (int i = 1; i < n; i++) {
        a[i] = (k * a[i - 1] + b) % m;
    }
    vector<int>dp = vector<int>(n + 1);
    dp[0] = -(m + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = m + 1;
    }
    for (int i = 0; i < n; i++) {
	    int j = int(upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin());
	    if (dp[j-1] < a[i] && a[i] < dp[j]) {
            dp[j] = a[i];
        }
    }
    int i = 1;
    while (dp[i] != m + 1) {
        i++;
    }
    cout << i - 1 << endl;
    return 0;
}