#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    double r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    double dist = sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2));
    if (int(dist / (r * 2)) < dist / (r * 2)) {
        cout << int(dist / (r * 2)) + 1 << endl;
    } else {
        cout << int(dist / (r * 2)) << endl;
    }
    return 0;
}