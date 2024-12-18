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
            cout << (float)x / (float)m << " " << n << endl;
            if ((float)x / (float)m >= n) {
                l = m;
            } else {
                r = m;
            }
            cout << l << " " << r << endl;
        }
        cout << l << endl;
    }
    return 0;
}