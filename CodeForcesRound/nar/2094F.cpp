#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<int> prime = {};

bool isPrime(int n) {
    for (auto &x : prime)
        if (n % x == 0) return 0;
    return 1;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (m % k != 0) {
        int cnt = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cout << cnt % k + 1 << " ";
                cnt++;
            }
            cout << endl;
        }
    } else {
        int cnt = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cout << (cnt + y) % k + 1 << " ";
                cnt++;
            }
            cout << endl;
        }
    }
}

int main() {
    for (int i = 2; i < 100000; i++)
        if (isPrime(i)) prime.push_back(i);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}