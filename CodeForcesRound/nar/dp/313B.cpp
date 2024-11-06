#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    vector<int> dp(s.size());
    for (int i = 0; i < s.size() - 1; i++)
        dp[i + 1] = dp[i] + (s[i + 1] == s[i]);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        cout << dp[r - 1] - dp[l - 1] << endl;
    }
    return 0;
}