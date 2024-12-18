#include <iostream>
#define ll long long
using namespace std;

ll nod(ll a, ll b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll a, b;
        cin >> a >> b;
        cout << (a * b) / nod(a, b) << endl;
    }
    return 0;
}