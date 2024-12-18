#include <iostream>
#define ll long long
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    cout << a << endl;
    return 0;
}