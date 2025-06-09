#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    if (max(abs(r - g), max(abs(g - b), abs(b - r))) <= 25) {
        cout << "ALLOWED" << endl;
    } else {
        cout << "FORBIDDEN" << endl;
    }
    return 0;
}