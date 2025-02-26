#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll x = 0;
        cin >> x;
        sum += x;
    }
    cout << sum / 100 << endl;
    return 0;
}