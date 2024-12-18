#include <iostream>
using namespace std;

int nod(int a, int b) {
    if (min(a, b) == 1) return 1;
    if (min(a, b) == 2 && max(a, b) & 1 == 0) return 2;
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
    int a, b;
    cin >> a >> b;
    cout << nod(a, b) << endl;
    return 0;
}