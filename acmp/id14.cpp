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
    int a, b;
    cin >> a >> b;
    cout << a * b / nod(a, b) << endl;
}