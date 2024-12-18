#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int>prime = {};

bool isPrime(int a) {
    for (auto &x : prime) {
        if (a % x == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    for (int i = 2; i * i <= 1000000000; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        if (a != 1) {
            int index = 0;
            while (index < prime.size() && a % prime[index] != 0) {
                index++;
            }
            if (index == prime.size()) {
                cout << a * b << endl;
            } else {
                cout << b * prime[index] << endl;
            }
        } else if (a == 1) {
            cout << b * b << endl;
        }
    }
    return 0;
}