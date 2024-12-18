#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int> prime;

bool isPrime(int n) {
    for (auto &x : prime) {
        if (n % x == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
    /*for (auto &x : prime)
        cout << x << " ";
    cout << endl;*/
    cout << ((isPrime(n))?"YES\n":"NO\n");
    return 0;
}