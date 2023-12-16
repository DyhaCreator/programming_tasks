#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int>prime = vector<int>();

bool isPrime(int n) {
    for (int i = 0; i < prime.size(); i++) {
        if (n % prime[i] == 0) {
            return false;
        }
    }
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
    if (prime.back() == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}