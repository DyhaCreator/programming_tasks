#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<ll> prime = {};

bool isPrime(ll n) {
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (ll i = 2; i * i <= n; i++) {
        if (isPrime(i))
            prime.push_back(i);
    }
    if (isPrime(n)) {
        cout << n << endl;
        return 0;
    }
    vector<ll> del = {};
    ll nn = n;
    for (auto &x : prime) {
        if (nn % x == 0)
            del.push_back(x);
        while (nn % x == 0) {
            nn /= x;
        }
    }
    if (nn != 1)
        del.push_back(nn);
    if (del.size() == 1) {
        cout << del[0] << endl;
    } else {
        cout << 1 << endl;
    }
    return 0;
}