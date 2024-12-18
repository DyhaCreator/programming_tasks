#include <iostream>
#define ll long long
using namespace std;

int nod(int a, int b) {
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
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << m << endl;
        return 0;
    }
    if (m == 1) {
        cout << n << endl;
        return 0;
    }
    if (n == m) {
        cout << n << endl;
        return 0;
    }
    cout << nod(n - 1, m - 1) + 1 << endl;
    return 0;
}