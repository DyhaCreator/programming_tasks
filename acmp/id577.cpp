#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<int> count(10, 0);

void f(ll n) {
    while (n > 0) {
        count[n % 10]++;
        n /= 10;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f(i * j);
        }
    }
    for (auto &x : count)
        cout << x << endl;
    return 0;
}