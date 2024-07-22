#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int> prime;
vector<int> del;

vector<int> n_prime;
vector<int> n_pow;

int f(int index, vector<int>pows, int num) {
    if (index >= n_pow.size()) {
        /*for (auto &x : pows)
            cout << x << " ";
        cout << endl;*/
        //cout << num << endl;
        del.push_back(num);
        return 0;
    }

    for (int i = 0; i <= n_pow[index]; i++) {
        pows[index] = i;
        f(index + 1, pows, num);
        num *= n_prime[index];
    }

    return 0;
}

bool isPrime(int n) {
    for (auto &x : prime) if (n % x == 0) return false;
    return true;
}

int nod(int a, int b) {
    if (a == 1) return 1;
    while (b > 0) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main() {
    // cout << 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23 << endl;
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
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
    n = save_n;
    
    f(0, vector<int>(n_pow.size(), 0), 1);
    /*for (auto &x : del)
        cout << x << " ";
    cout << endl;
    cout << del.size() << endl;*/

    int ans = 0;

    for (int i = 0; i < del.size() - 1; i++) {
        for (int j = i + 1; j < del.size(); j++) {
            // cout << del[i] << " " << del[j] << " " << nod(del[i], del[j]) << endl;
            if (del[i] * del[j] <= n && nod(del[i], del[j]) == 1) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}