#include <iostream>
#define ll long long
using namespace std;

int nod(int a, int b) {
    if (a == 1) return 1;
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
    for (int i = 1; i < n; i++) {
        if (nod(i, n) == 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}