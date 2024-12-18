#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#define ll unsigned long long

using namespace std;

int main() {
    int n;
    cin >> n;
    ll size = 0;
    ll j = 0;
    ll a = 0;
    for (ll i = 0; size < n + 1; i++) {
        a = i * i * i;
        ll b = 0;
        while (j * j < a) {
            b = j * j;
            if (b != (i - 1) * (i - 1) * (i - 1)) {
                size++;
                if (size >= n + 1) {
                    cout << b << endl;
                    return 0;
                }
            }
            j++;
        }
        size++;
    }
    cout << a << endl;
    return 0;
}