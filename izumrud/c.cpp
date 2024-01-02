#include <iostream>
using namespace std;

int f2(int i, int j) {
    int a = i % 16 + j % 16;
    i /= 16;
    j /= 16;
    int b = i % 16 + j % 16;
    return stoi(to_string(b) + to_string(a));
}

int f(int n) {
    for (int i = 16; i < 256; i++) {
        for (int j = 16; j < 256; j++) {
            if (f2(i, j) == n) {
                cout << i << " " << j << " " << f2(i, j) << endl;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cout << f(0xda) << endl;
    return 0;
}