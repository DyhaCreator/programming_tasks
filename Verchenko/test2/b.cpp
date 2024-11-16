#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

vector<int> prime = {};

bool isPrime(int n) {
    for (auto &x : prime) if (n % x == 0) return 0;
    return 1;
}

int main() {
    int n = 100;
    for (int i = 2; i < 100; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }
    int ans = 0;
    for (auto &x : prime) {
        for (auto &y : prime) {
            if (x == (y % 10 * 10) + (y / 10 % 10)) {
                cout << x << " " << y << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    for (auto &x : prime)
        cout << x << " ";
    cout << endl;
    return 0;
}