#include <bits/stdc++.h>
#include "lib.h"
using namespace std;
using ll = long long;

int main() {
    int n = 100;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++)
        a[i] = i;
    ll i = n;
    ll sch = 0;
    double g = (double)a[i] / 2;
    while (a[i] > n / 2) {
        while (a[i - 1] >= g) {
            ll t = a[i - 1];
            a[i - 1] = a[i];
            a[i] = t;
            sch++;
            i--;
        }
        i = n;
        g = (double)a[i] / 2;
    }
    cout << sch << endl;
    return 0;
}