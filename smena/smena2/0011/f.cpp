#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<int> prime = {};

bool isPrime(int n) {
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    if (n * m == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> unprime = {1};
    if (m == 1) {
        int cnt = 0;
        for (int i = 2; cnt < n; i++) {
            cout << i << endl;
            cnt++;
        }
        return 0;
    }
    if (n == 1) {
        int cnt = 0;
        for (int i = 2; cnt < m; i++) {
            cout << i << " ";
            cnt++;
        }
        cout << endl;
        return 0;
    }
    for (int i = 2; prime.size() < max(m, n) || unprime.size() < max(n, m); i++) {
        if (isPrime(i))
            prime.push_back(i);
        else
            unprime.push_back(i);
    }
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    int mx_a = 0;
    int mx_b = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            a[y][x] = prime[y] * unprime[x];
            b[y][x] = prime[x] * unprime[y];
            mx_a = max(mx_a, a[y][x]);
            mx_b = max(mx_b, b[y][x]);
        }
    }
    if (mx_a < mx_b) {
        for (auto &x : a) {
            for (auto &y : x)
                cout << y << " ";
            cout << endl;
        }
    } else {
        for (auto &x : b) {
            for (auto &y : x)
                cout << y << " ";
            cout << endl;
        }
    }
    return 0;
}