#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int> prime;

bool isPrime(int n) {
    for (auto &x : prime) if (n % x == 0) return false;
    return true;
}

ll pow(ll a, ll b) {
    ll ans = 1;
    for (int i = 0; i < b; i++)
        ans *= a;
    return ans;
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

    ll ans = 1;
    for (int i = 0; i < n_pow.size(); i++) {
        ans *= pow(n_prime[i], n_pow[i]) - pow(n_prime[i], n_pow[i] - 1);
    }
    cout << ans << endl;
    return 0;
}