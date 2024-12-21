#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<int> prime = {};

bool isPrime(int n) {
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; i++)
        if (n % prime[i] == 0) return 0;
    return 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (int i = 2; i <= n; i++)
        if (isPrime(i)) prime.push_back(i);
    prime.push_back(4);
    vector<int> del = {};
    for (auto &x : prime)
        if (n % x == 0 && x > 2) del.push_back(x);
    vector<vector<int>> dp(del.size(), vector<int>(n));
    int ans = 0;
    for (int i = 0; i < del.size(); i++) {
        for (int j = 0; j < n / del[i]; j++)
            dp[i][j] = a[j];
        for (int j = n / del[i]; j < n; j++)
            dp[i][j] = dp[i][j - n / del[i]] & a[j];
        for (int j = n - n / del[i]; j < n; j++)
            ans = ans | dp[i][j];
    }
    
    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}