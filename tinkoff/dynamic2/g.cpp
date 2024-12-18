#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>m = vector<int>(n);
    ll sum = 0;
    for (auto &x : m) {
        cin >> x;
        sum += x;
    }
    if (sum % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }
    vector<ll>dp = vector<ll>(sum / 2 + 1);
    vector<vector<int >> dp2 = vector<vector<int >> (sum / 2 + 1, vector<int>());
    dp[0] = 1;
    for (int i = 1; i < sum / 2 + 1; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= m[j]) {
                bool b = false;
                for (auto x : dp2[i - m[j]]) {
                    if (x == j) {
                        b = true;
                        break;
                    }
                }
                if (b == false && dp[i - m[j]] == 1) {
                    dp[i] = 1;
                    dp2[i] = dp2[i - m[j]];
                    dp2[i].push_back(j);
                    break;
                }
            }
        }
    }
    if (dp[sum / 2] == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}