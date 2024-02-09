#include <iostream>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 0, b = 1;
    while (n > 0) {
        a += b;
        b = a - b;
        n--;
    }
    cout << a << endl;
    return 0;
}