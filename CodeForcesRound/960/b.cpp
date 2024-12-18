#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        for (int j = 1 + (n - k - 1); j <= k + 1 + (n - k - 1); j++) {
            cout << j << " ";
        }
        for (int j = 1 + (n - k - 1) - 1; j > 0; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}