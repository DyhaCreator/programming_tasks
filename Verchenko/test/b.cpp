#include <iostream>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    int f1 = 0;
    int f2 = 1;
    int b = 1;
    int i = 1;
    while (i < n) {
        b = f1 + f2;
        f1 = f2;
        f2 = b;
        i = i + 1;
    }
    cout << b << endl;
    return 0;
}