#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> primes(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        int index = 2 * i;
        while (index <= n) {
            primes[index] = 0;
            index += i;
        }
    }
    int ans = 0;
    vector<int> b = {};
    for (int i = 3; i <= n; i++) {
        if (primes[i] == 1 && i + 2 <= n && primes[i + 2] == 1) {
            ans++;
            b.push_back(i);
        }
    }
    cout << ans << endl;
    for (auto &x : b)
        cout << 2 << " " << x << endl;
    return 0;
}