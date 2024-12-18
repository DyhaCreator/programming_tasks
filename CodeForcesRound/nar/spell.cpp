#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    while (n > 0) {
        int a = n;
        while (!isPrime(a)) {
            a--;
        }
        n -= a;
        cout << a << endl;
    }
    return 0;
}