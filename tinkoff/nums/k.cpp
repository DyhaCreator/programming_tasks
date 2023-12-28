#include <iostream>
#define ll long long
using namespace std;

int nod(int a, int b) {
    if (a == 0 || b == 0) {
        return max(a, b);
    }
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    int lx, ly;
    int x, y;
    cin >> lx >> ly;
    for (int i = 0; i < n - 1; i++) {
        lx = x;
        ly = y;
        cin >> x >> y;
        int vx = x - lx, vy = y - ly;
        ans += nod(abs(vx), abs(vy));
    }
    int vx = x - lx, vy = y - ly;
    ans += nod(abs(vx), abs(vy));
    cout << ans - 1 << endl;
    return 0;
}