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
    /*for (auto &x : prime)
        cout << x << " ";
    cout << endl;*/
    int save_n = n;
    vector<int> n_primes;
    vector<int> n_powers;
    int prime_index = 0;
    while (n > 1 && prime_index < prime.size()) {
        if (n % prime[prime_index] == 0) {
            if (n_primes.size() > 0 && n_primes.back() == prime[prime_index]) {
                n_powers[n_powers.size() - 1]++;
            } else {
                n_primes.push_back(prime[prime_index]);
                n_powers.push_back(1);
            }
            n /= prime[prime_index];
        } else {
            prime_index++;
        }
        // cout << n << endl;
    }
    if (n > 1) {
        n_primes.push_back(n);
        n_powers.push_back(1);
    }
    n = save_n;
    /*for (auto &x : n_primes)
        cout << x << " ";
    cout << endl;
    for (auto &x : n_powers)
        cout << x << " ";
    cout << endl;*/

    ll ans1 = 1;
    for (auto &x : n_powers)
        ans1 *= x + 1;
    cout << ans1 << " ";
    
    ll ans = 1;
    for (int i = 0; i < n_powers.size(); i++) {
        ll aaa = 0;
        ll bbb = 1;
        for (int j = 0; j <= n_powers[i]; j++) {
            aaa += bbb;
            bbb *= n_primes[i];
        }
        // cout << aaa << " ";
        ans *= aaa;
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}