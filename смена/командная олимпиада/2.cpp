#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > 2 * n) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";
    if (a > b) {
        int i = 1;
        while (a != 0) {
            if (i % 2 != 0) {
                for (int j = 0;  j < min(3, a); j++) {
                    cout << i << " ";
                }
            }
            i += 2;
        }
        cout << "\n";
        i = 2;
        while (b != 0) {
            if (i % 2 != 0) {
                for (int j = 0;  j < min(2, b); j++) {
                    cout << i << " ";
                }
            }
            i += 2;
        }
        cout << "\n";
    } else {
        int i = 2;
        while (a != 0) {
            if (i % 2 != 0) {
                for (int j = 0;  j < min(2, a); j++) {
                    cout << i << " ";
                }
            }
            i += 2;
        }
        cout << "\n";
        i = 1;
        while (b != 0) {
            if (i % 2 != 0) {
                for (int j = 0;  j < min(3, b); j++) {
                    cout << i << " ";
                }
            }
            i += 2;
        }
        cout << "\n";
    }
}