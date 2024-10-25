#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b > 0 || c > 0) {
        if (max(b, c) - min(b, c) >= 1) {
            cout << a + d + min(b, c) * 2 + 1 << endl;
        } else {
            cout << a + d + min(b, c) * 2 << endl;
        }
    } else {
        cout << max(a, d) << endl;
    }
    return 0;
}