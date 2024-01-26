#include <iostream>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int u = 0, d = 0, l = 0, r = 0;
        for (int j = 0; j < n; j++) {
            int x, y;
            cin >> x >> y;
            if (x > 0) {
                l++;
            } else if (x < 0) {
                r++;
            }
            if (y > 0) {
                u++;
            } else if (y < 0) {
                d++;
            }
        }
        int count = 0;
        if (u > 0) count++;
        if (d > 0) count++;
        if (l > 0) count++;
        if (r > 0) count++;
        if (count == 4) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}