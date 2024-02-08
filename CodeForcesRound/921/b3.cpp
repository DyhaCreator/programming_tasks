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
        int g = x / n;
        int ans = 1;
        while (g > 0) {
            if (x % g == 0 && x / g >= n) {
                ans = g;
                break;
            }
            g--;
        }
        cout << ans << endl;
    }
    return 0;
}