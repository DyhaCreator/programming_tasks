#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll nod(ll a, ll b) {
    if (a == 1 || b == 1) return 1;
    while (b > 0) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << a * b / nod(a, b) << endl;
    return 0;
}