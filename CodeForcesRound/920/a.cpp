#include <iostream>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b, c, d;
        cin >> a >> b;
        cin >> c >> d;
        int l;
        if (a != c) {
            l = abs(a - c);
        } else if (d != b) {
            l = abs(b - d);
        }
        cout << l * l << endl;
        cin >> a >> b >> a >> b;
    }
    return 0;
}