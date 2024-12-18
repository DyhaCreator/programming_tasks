#include <iostream>
#define ll long long
using namespace std;

ll f(int n) {
    ll a = 0, b = 1;
    while (n > 0) {
        a += b;
        b = a - b;
        n--;
    }
    return a;
}

int main() {
    int target;
    cin >> target;
    int l = 0;
    int r = 50;
    while (l < r) {
        int m = (l + r) / 2;
        if (f(m) < target) {
            l = m + 1;
        } else {
            r = m;
        }
        //cout << l << " " << r << endl;
    }
    if (f(l) == target) {
        cout << 1 << endl;
        cout << l << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}