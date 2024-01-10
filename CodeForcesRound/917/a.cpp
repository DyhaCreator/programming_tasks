#include <iostream>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        ll a = 1;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x < 0) {
                a = -a;
            } else if (x == 0) {
                a = 0;
            }
        }
        if (a > 0) {
            cout << "1\n1 0" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    return 0;
}