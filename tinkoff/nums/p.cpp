#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll a, p;
    cin >> a >> p;
    ll i = 1;
    while ((p * i + 1) % a != 0) {
        i++;
    }
    cout << (p * i + 1) / a << endl;
    return 0;
}