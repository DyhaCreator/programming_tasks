#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, n;
        cin >> x >> n;
        int l = 1;
        int r = x;
        for (int j = 0; j < 10; j++) {
            int m = (l + r) / 2;
            if (x / m > n) {
                l = m;
            } else {
                r = m;
            }
            // cout << m << " " << x / m << endl;
        }
        cout << l << endl;
    }
    return 0;
}