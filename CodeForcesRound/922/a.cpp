#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, m;
        cin >> n >> m;
        cout << n * (m / 2) << endl;
    }
    return 0;
}