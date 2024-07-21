#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int> prime;

bool isPrime(int n) {
    for (auto &x : prime) if (n % x == 0) return false;
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
    int save_n = n;
    vector<int> n_prime;
    vector<int> n_pow;
    int index = 0;
    while (n > 1 && index < prime.size()) {
        if (n % prime[index] == 0) {
            if (n_prime.size() > 0 && n_prime.back() == prime[index]) {
                n_pow[n_pow.size() - 1]++;
            } else {
                n_prime.push_back(prime[index]);
                n_pow.push_back(1);
            }
            n /= prime[index];
        } else {
            index++;
        }
    }
    if (n > 1) {
        n_prime.push_back(n);
        n_pow.push_back(1);
    }
    /*for (auto &x : n_prime)
        cout << x << " ";
    cout << endl;
    for (auto &x : n_pow)
        cout << x << " ";
    cout << endl;*/
    if (n_pow[0] == 1) {
        cout << n_prime[0];
    } else {
        cout << n_prime[0] << "^" << n_pow[0];
    }
    for (int i = 1; i < n_pow.size(); i++) {
        cout << "*" << n_prime[i];
        if (n_pow[i] > 1) {
            cout << "^" << n_pow[i];
        }
    }
    cout << endl;
    return 0;
}