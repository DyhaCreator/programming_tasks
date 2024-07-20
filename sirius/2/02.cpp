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

int main() {
    int n;
    cin >> n;
    bool isFind = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
            if (n % i == 0) {
                cout << i << endl;
                isFind = true;
                break;
            }
        }
    }
    if (!isFind) {
        cout << n << endl;
    }
    return 0;
}