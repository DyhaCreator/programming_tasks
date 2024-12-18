#include <iostream>
#define ll long long
using namespace std;

int nod(int a, int b) {
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
    if (n % 2 == 0) {
        cout << n / 2 << " " << n / 2 << endl;
        return 0;
    }
    int maxNod = 1;
    int a = 1;
    for (int i = 1; i <= n / 2; i++) {
        int newNod = nod(i, n - i);
        if (newNod > nod(a, n - a)) {
            a = i;
            maxNod = newNod;
        }
    }
    cout << a << " " << n - a << endl;
    return 0;
}