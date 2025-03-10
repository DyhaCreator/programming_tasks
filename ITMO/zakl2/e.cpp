#include <bits/stdc++.h>
#include "lib.h"
using namespace std;
using ll = long long;

int main() {
    for (int i = 0; i < 8; i++) {
        bool a = i & 1;
        bool b = (i & 0b10) >> 1;
        bool c = (i & 0b100) >> 2;
        cout << (b && !c || b && a && !c || b && a) << " ";
        cout << (sled(sled(a, b), !c)) << " ";
        cout << (!a && !b || c && a) << endl;
    }
    return 0;
}