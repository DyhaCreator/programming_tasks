#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll nod(ll a, ll b) {
    /*if (a % 2 != b % 2) {
        return 1;
    }*/
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
    //cout << nod(295619042, 443428563) << endl;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll a, b;
        cin >> a >> b;
        if (b % a == 0) {
            cout << b * (b / a) << endl;
        } else {
            cout << b * (a / nod(a, b)) << endl;
        }
    }
    return 0;
}