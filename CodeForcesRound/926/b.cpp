#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, k;
        cin >> n >> k;
        if (k <= (4 * n - 2) - 2) {
            cout << (k + 1) / 2 << endl;
        } else {
            if (k == 4 * n - 2) {
                cout << n * 2 << endl;
            } else {
                cout << n * 2 - 1 << endl;
            }
        }
    }
    return 0;
}