#include <bits/stdc++.h>
#include "lib.h"
using namespace std;
using ll = long long;

int main() {
    ll a = 4*16;
    ll b = 8;
    ll c = 2;
    ll a1 = 1;
    ll b1 = 1;
    ll c1 = 1;
    for (int i = 0; i < 10; i++) {
        cout << i << endl;
        cout << t_to_all(a1 - b1 - c1, 2) << endl;
        a1 *= a;
        b1 *= b;
        c1 *= c;
    }
    return 0;
}