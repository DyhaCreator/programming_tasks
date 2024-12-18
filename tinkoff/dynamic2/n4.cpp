#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll a = 0;
    ll b = 1;
    while (n > 0) {
        a += b;
        b = a - b;
        n--;
    }
    cout << b << endl;
    return 0;
}