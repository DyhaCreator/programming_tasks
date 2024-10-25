#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

vector<ll> prime = {};

bool isPrime(ll n) {
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) return 0;
    }
    return 1;
}

int main() {
    ll n;
    cin >> n;
    for (ll i = 2; i * i <= n; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
            // cout << i << endl;
        }
    }
    /*for (auto &x : prime)
        cout << x << " ";
    cout << endl;*/
    vector<ll> myPrime = {};
    vector<ll> col = {};
    ll nn = n;
    int index = 0;
    while (index < prime.size()) {
        if (nn % prime[index] == 0) {
            if (myPrime.size() >= 1 && myPrime.back() == prime[index]) {
                col[col.size() - 1]++;
            } else {
                myPrime.push_back(prime[index]);
                col.push_back(1);
            }
            nn /= prime[index];
        } else {
            index++;
        }
        // cout << index << endl;
    }
    if (nn > 1) {
        myPrime.push_back(nn);
        col.push_back(1);
    }
    /*for (auto &x : myPrime)
        cout << x << " ";
    cout << endl;
    for (auto &x : col)
        cout << x << " ";
    cout << endl;*/
    ll ans = 1;
    for (int i = 0; i < myPrime.size(); i++) {
        if (col[i] % 2 == 1) {
            ans *= myPrime[i];
        }
    }
    cout << ans << endl;
    return 0;
}