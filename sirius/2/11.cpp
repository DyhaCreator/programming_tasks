#include <iostream>
#include <vector>
#define ll long long
#define INF 100000007
using namespace std;

vector<int> prime;

bool isPrime(int n) {
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; i++)
        if (n % prime[i] == 0) return false;
    return true;
}

int main() {
    int k;
    cin >> k;
    prime = vector<int>(k, INF);
    int i = 2;
    while (prime.size() < k) {
        if (isPrime(i)) {
            prime.push_back(i);
            // cout << i << endl;
        }
        i++;
    }
    /*for (auto &x : prime)
        cout << x << " ";
    cout << endl;*/
    cout << prime[k - 1] << endl;
    return 0;
}