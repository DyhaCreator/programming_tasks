#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int> prime = {};

bool isPrime(int n) {
    for (auto &x : prime)
        if (n % x == 0 && n != x) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
    for (auto &x : prime) {
        if (isPrime(n - x)) {
            cout << x << " " << n - x << endl;
            return 0;
        }
        //cout << x << ' ' << n - x << endl;
    }
    //cout << a << " " << b << endl;
    return 0;
}