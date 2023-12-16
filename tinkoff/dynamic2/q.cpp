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
    vector<int>dp = vector<int>(n);
    dp[0] = 1;
    int maxL = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j] > dp[i]) {
                dp[i] = dp[j];
            }
        }
        dp[i]++;
        if (dp[i] > maxL) {
            maxL = dp[i];
        }
    }
    cout << maxL << endl;
    return 0;
}