#include <bits/stdc++.h>
#include "lib.h"
using namespace std;
using ll = long long;

int main() {
    vector<double> a(1024);
    vector<double> b(1024);
    vector<double> c(1024);
    vector<double> d(1024);
    a[0] = 5;
    b[0] = 4;
    c[0] = 3;
    for (int i = 1; i < 102; i++) {
        a[i] = a[i - 1] + 15.0 / 25;
        b[i] = b[i - 1] + 4.0 / 16 * 15;
        c[i] = c[i - 1] + (15.0 / 40);
        double sum = a[i] + b[i] + c[i];
        cout << a[i] << " " << b[i] << " " << c[i] << endl;
        cout << sum << endl;
        /*if (int(sum * 100000) % 100000 == 0) {
            cout << sum << endl;
        }*/
    }
    return 0;
}