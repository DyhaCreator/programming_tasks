#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<int> prime = {};

bool isPrime(int n) {
    for (auto &x : prime)
        if (n % x == 0) return 0;
    return 1;
}

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 2; i <= max(a, b); i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
    for (int i = 0; i < prime.size(); i++) {
        vector<pair<int, int>> d = {};
        for (int j = 0; j <= prime[i]; j++) {
            int l = 0;
            int r = prime[i];
            while (l < r) {
                int m = (l + r) / 2;
                if (m * m + j * j < prime[i] * prime[i]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            if (r * r + j * j == prime[i] * prime[i])
                d.push_back({r, j});
        }
        if (a % prime[i] == 0 && b % prime[i] == 0 && d.size() > 2) {
            if (d[2].F * b / prime[i] == d[1].F * a / prime[i]) {
                cout << "YES" << endl;
                cout << 0 << " " << 0 << endl;
                cout << d[1].F * a / prime[i] << " " << d[1].S * a / prime[i] << endl;
                cout << -d[2].F * b / prime[i] << " " << d[2].S * b / prime[i] << endl;
            } else {
                cout << "YES" << endl;
                cout << 0 << " " << 0 << endl;
                cout << d[1].F * a / prime[i] << " " << -d[1].S * a / prime[i] << endl;
                cout << d[2].F * b / prime[i] << " " << d[2].S * b / prime[i] << endl;
            }
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}