#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a = vector<int>(n);
    for (auto &x : a)
        cin >> x;
    vector<int>dp = vector<int>(n, 0);
    vector<vector<int >> b = vector<vector<int >> (n, vector<int>());
    dp[0] = 1;
    b[0].push_back(a[0]);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j] > dp[i]) {
                dp[i] = dp[j];
                b[i] = b[j];
            }
        }
        b[i].push_back(a[i]);
        dp[i]++;
    }
    int indexMax = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > dp[indexMax]) {
            indexMax = i;
        }
    }
    cout << dp[indexMax] << endl;
    for (auto x : b[indexMax])
        cout << x << " ";
    cout << endl;
    return 0;
}