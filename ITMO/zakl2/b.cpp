#include <bits/stdc++.h>
#include "lib.h"
using namespace std;
using ll = long long;

int main() {
    int x;
    cin >> x;
    int t = 0;
    vector<int> a(40);
    do {
        int y = x % 10;
        do {
            t++;
            a[t] = y % 2;
            y /= 2;
        } while (y != 0);
        if (t % 4 != 0) {
            t = t + 4 - (t % 4);
        }
        x /= 10;
    } while (x != 0);
    do {
        cout << a[t] << " ";
        t--;
    } while (t != 0);
    cout << endl;
    return 0;
}