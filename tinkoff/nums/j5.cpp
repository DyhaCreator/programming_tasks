#include <iostream>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    int d = 1;
    for (int q = 2; q * q <= n; q++) {
        if (n % q == 0) {
            d = n / q;
            break;
        }
    }
    cout << d << " " << n - d << endl;
    return 0;
}