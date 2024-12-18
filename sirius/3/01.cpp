#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int> prime;
vector<int> even_prime;

vector<int> n_prime;
vector<int> n_pow;

bool isPrime(int n) {
    for (auto &x : prime)
        if (n % x == 0) return false;
    return true;
}

bool isEvenPrime(int n) {
    return (n / 2) % 2 != 0;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime(i)) prime.push_back(i);
        if (i % 2 == 0 && isEvenPrime(i)) even_prime.push_back(i);
    }
    /*for (auto &x : prime)
        cout << x << " ";
    cout << endl;
    for (auto &x : even_prime)
        cout << x << " ";
    cout << endl;*/
    if (isEvenPrime(n)) {
        cout << "prime" << endl;
        return 0;
    }
    int save_n = n;
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

    int pow_sum = 0;
    for (int i = 1; i < n_pow.size(); i++) {
        pow_sum += n_pow[i];
    }

    int last = 2;
    for (int i = 1; i < n_pow.size(); i++) {
        for (int j = 0; j < n_pow[i]; j++) {
            last *= n_prime[i];
        }
    }

    if (n_pow[0] >= 2 && pow_sum >= 2) {
        cout << "many" << endl;
        for (int i = 0; i < n_pow[0] - 1; i++) {
            cout << 2 << " ";
        }
        cout << last << endl;
        for (int i = 0; i < n_pow[0] - 2; i++) {
            cout << 2 << " ";
        }
        cout << last / n_prime[1] << " ";
        cout << 2 * n_prime[1] << endl;

    } else {
        cout << "single" << endl;
        for (int i = 0; i < n_pow[0] - 1; i++) {
            cout << 2 << " ";
        }
        cout << last << endl;
    }
    return 0;
}