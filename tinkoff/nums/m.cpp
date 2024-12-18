#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int>prime = vector<int>();

bool isPrime(int n) {
    for (auto x : prime)
        if (n % x == 0) return false;
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
    for (int i = 0; i < prime.size() - 1; i++) {
        for (int j = i; j < prime.size(); j++) {
            if (prime[i] + prime[j] == n) {
                cout << prime[i] << " " << prime[j] << endl;
                return 0;
            }
        }
    }
    return 0;
}