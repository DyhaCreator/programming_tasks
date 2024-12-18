#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main() {
    /*int l = 0;
    int r = 100;
    while (l < r) {
        float m = (l + r) / 2;
        float a = 16 - m * 0.5 + 24 - m * 0.5 + 24 - m * 0.5;
        cout << a << endl;
        if (a > 0) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    
    cout << 16 - l * 0.5 + 24 - l * 0.5 + 24 - l * 0.5 << endl;
    cout << l << endl;*/

    for (float m = 0; m < 100; m++) {
        float a = 16 - m * 0.5 + 24 - m * 0.5 + 24 - m * 0.5;
        cout << m << " " << a << endl;
    }
    return 0;
}