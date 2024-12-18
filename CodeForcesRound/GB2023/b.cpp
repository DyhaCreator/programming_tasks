#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int>prime = {};

bool isPrime(int n) {
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) return false; 
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        if (prime.size() * prime.size() < std::max(a, b)) {
            for (int j = 2; j * j <= std::max(a, b); j++) {
                if (isPrime(j)) {
                    prime.push_back(j);
                    //cout << j << " ";
                }
            }
            //cout << endl;
        }
        vector<int>primeA = {};
        vector<int>primeB = {};
        int primeAsize = 0;
        int primeBsize = 0;
        int la = a, lb = b;
        int index = 0;
        int fA = 0;
        while (a > 1 && index < prime.size()) {
            if (a % prime[index] == 0) {
                if (fA == 0) {
                    fA = prime[index];
                }
                a /= prime[index];
                primeAsize++;
                primeA.push_back(prime[index]);
            } else {
                index++;
            }
        }
        if (a > 1) {
            if (fA == 0) {
                fA = a;
            }
            primeA.push_back(a);
            primeAsize++;
        }
        a = la;
        for (auto x : primeA)
            cout << x << " ";
        cout << endl;
        index = 0;
        while (b > 1 && index < prime.size()) {
            if (b % prime[index] == 0) {
                b /= prime[index];
                primeBsize++;
                primeB.push_back(prime[index]);
            } else {
                index++;
            }
        }
        if (b > 1) {
            primeB.push_back(b);
            primeBsize++;
        }
        b = lb;
        for (auto x : primeB)
            cout << x << " ";
        cout << endl;

        if (primeAsize == 0 && primeBsize == 1) {
            cout << b * b << endl;
        } else if (primeAsize == 1 && primeBsize == 1) {
            cout << a * b << endl;
        } else {
            cout << b * fA << endl;
        }
    }
    return 0;
}