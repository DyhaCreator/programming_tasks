#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    if (y1 == y2 || x1 == x2) {
        cout << 1 << ' ';
    } else {
        cout << 2 << ' ';
    }
    if ((y2 + x2) % 2 == (y1 + x1) % 2) {
        if (y2 - y1 == x2 - x1 || -(y2 - y1) == x2 - x1) {
            cout << 1 << ' ';
        } else {
            cout << 2 << ' ';
        }
    } else {
        cout << 0 << ' ';
    }
    cout << max(abs(y2 - y1), abs(x2 - x1)) << endl;
    return 0;
}