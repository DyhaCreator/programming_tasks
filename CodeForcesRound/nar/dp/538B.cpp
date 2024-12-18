#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int f(int n) {
    vector<int> a = {};
    while (n > 0) {
        a.push_back(n % 2);
        n /= 2;
    }
    int ans = 0;
    reverse(a.begin(), a.end());
    for (auto &x : a)
        ans = ans * 10 + x;
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, INF);
    vector<int> pref(n + 1, -1);

    vector<int> nums = {};
    for (int j = 0; j <= (1 << 6); j++) {
        int num = f(j);
        nums.push_back(num);
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto &num : nums) {
            if (num <= i) {
                if (dp[i] > dp[i - num] + 1) {
                    dp[i] = dp[i - num] + 1;
                    pref[i] = num;
                }
            }
        }
    }
    int index = n;
    cout << dp[n] << endl;
    while (index != 0) {
        cout << pref[index] << " ";
        index -= pref[index];
    }
    cout << endl;
    return 0;
}