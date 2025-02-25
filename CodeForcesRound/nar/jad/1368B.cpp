#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<int> prime = {};

bool isPrime(int n) {
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; i++)
        if (n % prime[i] == 0) return 0;
    return 1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++)
        if (isPrime(i)) prime.push_back(i);
    for (auto &x : prime)
        cout << x << " ";
    cout << endl;
    vector<int> del = {};
    int m = n;
    for (auto &x : prime) {
        while (m % x == 0) {
            m /= x;
            del.push_back(x);
        }
    }
    reverse(del.begin(), del.end());
    for (auto &x : del)
        cout << x << " ";
    cout << endl;
    string s = "codeforces";
    for (int i = 0; i < s.size(); i++) {
        if (i < del.size()) {
            for (int i = 0; i < n; i++)
        }
    }
    return 0;
}