#include <bits/stdc++.h>
#include "lib.h"
using namespace std;
using ll = long long;

int main() {
    vector<int> a(10);
    a[0] = 7;
    for (int i = 1; i < 10; i++)
        a[i] = a[0] * a[i - 1];
    vector<int> b(10);
    for (b[0] = 1; b[0] <= 20000; b[0]++) {
        for (int i = 1; i < 10; i++)
            b[i] = a[i] % b[0];
        int f = 0;
        for (int i = 1; i < 10; i++)
            if (b[i] != b[1]) f = 1;
        int sum = 0;
        for (auto &x : b)
            sum += x;
        sum -= b[0];
        if (f == 0 && sum == 63) {
            cout << b[0] << endl;
        }
    }
    return 0;
}