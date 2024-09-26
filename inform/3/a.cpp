#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll a, b;
    cin >> a >> b;
    ll k = 0;
    ll l = 1;
    while (l <= 1000) {
        ll c = l * l * l;
        if (a <= c && c <= b) {

            k++;
        }
        l++;
    }
    cout << k << endl;
    return 0;
}