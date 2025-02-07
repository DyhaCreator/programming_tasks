#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<int> prime = {};

bool isPrime(int n) {
    for (auto &x : prime) {
        if (n % x == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) prime.push_back(i);
    }
    vector<ll> cnt(prime.size(), 0);
    for (int i = 1; i <= n; i++) {
        int m = i;
        for (int j = 0; j < prime.size(); j++) {
            int m = i;
            while (m % prime[j] == 0) {
                m /= prime[j];
                cnt[j]++;
            }
        }
    }
    ll ans = 1;
    for (auto &x : cnt) {
        ans *= x + 1;
    }
    cout << ans << endl;
    return 0;
}