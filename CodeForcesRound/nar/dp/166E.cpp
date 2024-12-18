#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    ll a_last = 1;
    ll b_last = 0;
    for (int i = 1; i <= n; i++) {
        ll a_new = (b_last * 3LL) % 1000000007;
        ll b_new = (a_last + b_last * 2) % 1000000007;
        a_last = a_new;
        b_last = b_new;
    }
    cout << a_last<< endl;
    return 0;
}
