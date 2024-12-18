#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <set>
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
    vector<int> ex(100001);
    for (auto &x : a)
        ex[x] = 1;

    for (int i = 2; i <= 100000; i++) {
        if (isPrime(i))
            prime.push_back(i);
    }
    vector<int> dp(prime.size());
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int index = 0;
        int index_last = -1;
        set<int> st;
        while (index < prime.size() && prime[index] <= x && x > 0) {
            if (x % prime[index] == 0) {
                st.insert(index);
                x /= prime[index];
            } else index++;
        }
        int mx = 0;
        for (auto &x : st)
            if (dp[x] > mx) mx = dp[x];
        for (auto &x : st)
            dp[x] = mx + 1;
    }
    int ans = 1;
    for (auto &x : dp)
        ans = max(ans, x);
    cout << ans << endl;
    return 0;
}