#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    for (int y = 0; y < 9; y++) {
        for (int z = 0; z < 9; z++) {
            if ((z * 1 + y * 9 + 5 * 81) + (y * 1 + 5 * 12 + z * 144) + (5 + z * 16 + y * 256) == 2024) {
                cout << y << " " << z << endl;
            }
        }
    }
    return 0;
}