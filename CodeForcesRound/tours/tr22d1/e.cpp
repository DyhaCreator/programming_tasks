#include <bits/stdc++.h>
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
    int n;
    cin >> n;
    for (int i = 2; prime.size() < n; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
    for (auto &x : prime)
        cout << x << " ";
    cout << endl;
    return 0;
}