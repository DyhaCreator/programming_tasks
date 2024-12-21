#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll a = 1;
    ll b = 1;
    ll sum = 2;
    int n;
    cin >> n;
    if (n == 0) sum = 0;
    else if (n == 1) sum = 1;
    n -= 2;
    while (n-- > 0) {
        b += a;
        a = b - a;
        sum += b;
    }
    cout << sum << endl;
    return 0;
}