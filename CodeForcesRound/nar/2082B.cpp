#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<int> prime = {};

bool isPrime(int n) {
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) return 0;
    }
    return 1;
}

void solve() {
    int x, n, m;
    cin >> x >> n >> m;
    if (n > 32) {
        cout << "0 0" << endl;
        return;
    }
    m = min(m, 64);
    for (int i = 2; i * i <= x; i++)
        if (isPrime(i)) prime.push_back(i);
    vector<int> del = {};
    int save = x;
    for (auto &y : prime) {
        while (x % y == 0) {
            del.push_back(y);
            x /= y;
        }
    }
    if (x > 1)
        del.push_back(x);
    for (auto &x : del)
        cout << x << " ";
    cout << endl;
    vector<int> del2 = del;
    int a = n;
    int b = m;
    for (auto &x : del2) {
        
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}