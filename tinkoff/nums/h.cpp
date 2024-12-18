#include <iostream>
#define ll long long
using namespace std;

int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    cin >> ans;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        ans = gcd(ans, x);
    }
    cout << ans << endl;
    return 0;
}