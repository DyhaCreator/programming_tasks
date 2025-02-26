#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n, m;
    cin >> n >> m;
    string name;
    cin >> name;
    ll ans = n * (m - 1) + n;
    cout << (ans % 2) + 1 << endl;
    return 0;
}