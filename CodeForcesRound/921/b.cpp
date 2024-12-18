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
        int g = 1;
        int ans = 0;
        while (true) {
            if (x % g == 0 && x / g >= n) {
                ans = g;
            }
            if (x / g < n) break;
            g++;
        }
        cout << ans << endl;
    }
    return 0;
}