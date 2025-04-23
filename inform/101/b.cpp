#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll a, b, c;
    ll a1, b1, c1;
    cin >> a >> b >> c;
    cin >> a1 >> b1 >> c1;
    if (a * b * c > a1 * b1 * c1) {
        cout << "FIRST" << endl;
    } else if (a * b * c < a1 * b1 * c1) {
        cout << "SECOND" << endl;
    } else {
        cout << "EQUAL" << endl;
    }
    return 0;
}