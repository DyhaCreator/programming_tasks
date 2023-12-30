#include <iostream>
#define ll long long
using namespace std;

int main() {
    int a, p;
    cin >> a >> p;
    ll x = 1;
    while ((a * x - 1) % p != 0) {
        x++;
    }
    cout << x << endl;
    return 0;
}