#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int>prime = {2};

bool isPrime(int n) {
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; i++) {
    //for (auto &x : prime) {
        if (n % prime[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    for (int i = 3; i < n; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
            //cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}