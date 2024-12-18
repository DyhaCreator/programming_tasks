#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    while (n % 2 == 0) {
        n = n / 2;
    }
    while (n % 5 == 0) {
        n = n / 5;
    }
    if (n > 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}