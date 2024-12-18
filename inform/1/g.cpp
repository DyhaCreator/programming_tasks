#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    double x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
        cout << 0 << endl;
    } else if (x == 0 && y != 0) {
        cout << "Ordinate axis" << endl;
    } else if (x != 0 && y == 0) {
        cout << "Abscissa axis" << endl;
    } else if (x > 0 && y > 0) {
        cout << 1 << endl;
    } else if (x < 0 && y > 0) {
        cout << 2 << endl;
    } else if (x < 0 && y < 0) {
        cout << 3 << endl;
    } else if (x > 0 && y < 0) {
        cout << 4 << endl;
    }
    return 0;
}