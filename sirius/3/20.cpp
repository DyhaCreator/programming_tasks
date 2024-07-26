#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int nod(int a, int b) {
    if (a == 1 || b == 1) return 1;
    while (b > 0) {
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
    if (a == 0) {
        cout << "0 1" << endl;
        return 0;
    }
    cout << a / nod(abs(a), b) << " " << b / nod(abs(a), b) << endl;
    return 0;
}