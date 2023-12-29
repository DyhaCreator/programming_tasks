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
    for (int i = 2; i < 100; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}