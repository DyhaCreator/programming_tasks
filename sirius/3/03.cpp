#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int> prime;

bool isPrime(int n) {
    for (auto &x : prime) {
        if (x == n) return true;
        if (n % x == 0) return false;
    }
    return true;
}

int main() {
    int a, b;
    cin >> a >> b;

    for (int i = 2; i < b; i++) {
        if (isPrime(i)) prime.push_back(i);
    }

    vector<int> arr(b + 1, 0);
    for (int i = 0; i < int(prime.size()); i++) {
        for (int j = 0; j < int(prime.size()); j++) {
            if (prime[i] + prime[j] <= b) arr[prime[i] + prime[j]] = 1;
        }
    }
    for (int i = a; i <= b; i++) {
        if (arr[i] == 1) cout << i << endl; 
    }
    return 0;
}