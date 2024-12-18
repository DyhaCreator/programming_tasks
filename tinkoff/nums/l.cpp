#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int>prime = vector<int>();

bool isPrime(int n) {
    for (int i = 0; i * i < prime.size(); i++) {
        if (n % prime[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 2; i <= b; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
    for (auto x : prime)
        if (x <= b && x >= a)
            cout << x << " ";
    cout << endl;
    return 0;
}