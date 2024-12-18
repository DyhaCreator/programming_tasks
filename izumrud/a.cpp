#include <iostream>
#define ll long long
using namespace std;

int main() {
    for (int n = 2; n < 10; n++) {
        int x = 12 + 12 * n - 47;
        int y = 8 * n - 2 - 18;
        cout << n << " " << x << " " << x % n << "  " << y << " " << y % n << endl;
    }
    return 0;
}