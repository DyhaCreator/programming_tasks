#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int> prime;

bool isPrime(int n) {
    for (auto &x : prime)
        if (n % x == 0) return false;
    return true;
}

ll pow(ll a, ll b, ll p) {
    vector<int> del;
    ll save_b = b;
    int index = 0;
    while (b > 1 && index < prime.size()) {
        if (b % prime[index] == 0) {
            b /= prime[index];
            del.push_back(prime[index]);
        } else {
            index++;
        }
    }
    if (b > 1) del.push_back(b);
    b = save_b;

    /*for (auto &x : del)
        cout << x << " ";
    cout << endl;*/

    ll ans = 1;

    for (auto &x : del) {
        // cout << x << " ";
        for (int i = 0; i < x; i++) {
            ans *= a;
            ans = ans % p;
            // cout << ans << " ";
        }
        // cout << endl;
        a = ans;
        ans = 1;
    }
    return a;
}

ll f(ll p, ll a) {
    // cout << p << " " << a << endl;
    // cout << pow(a, p - 2, p) << endl;
    return pow(a, p - 2, p);
}

int main() {
    for (int i = 2; i * i <= 1000000000; i++) {
        if (isPrime(i)) prime.push_back(i);
    }
    /*for (auto &x : prime)
        cout << x << " ";
    cout << endl;*/
    // cout << pow(2, 3, 100000) << endl;
    int n;
    cin >> n;
    int p, a;
    for (int i = 0; i < n; i++) {
        cin >> p >> a;
        cout << f(p, a) << endl;
    }
    return 0;
}