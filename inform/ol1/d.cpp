#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

vector<int> prime = {};

bool isPrime(int n) {
    for (auto &x : prime) {
        if (n % x == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
    int index = 0;
    vector<int> a = {};
    while (index < prime.size()) {
        if (n % prime[index] == 0) {
            a.push_back(prime[index]);
            n /= prime[index];
        } else {
            index++;
        }
    }
    for (int i = 0; i < a.size(); i++) {
        if (i < a.size() - 1) {
            cout << a[i] << "*";
        } else {
            cout << a[i];
        }
    }
    if (n > 1 && a.size() > 0) cout << "*" << n << endl;
    else if (n > 1 && a.size() == 0) cout << n << endl;
    else cout << endl;
    return 0;
}